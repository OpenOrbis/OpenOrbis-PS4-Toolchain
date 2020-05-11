#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "graphics.h"

// Direct video memory pointer and pointer to frame buffer array
void *VideoMem;
void **FrameBuffers;

// Video mem trackers, flip event queue, and frame buffer attributes
uintptr_t VideoMemSP;
OrbisKernelEqueue FlipQueue;
OrbisVideoOutBufferAttribute Attr;
off_t DirectMemOff;
size_t DirectMemAllocationSize;

// Default width, height, and depth
int Width = 1920;
int Height = 1080;
int Depth = 4;

// Default frame buffer is always set to 0
int ActiveFrameBufferIdx = 0;

// Frame buffer size and count isn't initialized until allocateFrameBuffers() is called
int FrameBufferSize = 0;
int FrameBufferCount = 0;

// Linearly interpolate x with y over s
inline float lerp(float x, float y, float s)
{
    return x * (1.0f - s) + y * s;
}

// setDimensions sets the width, height, and depth of the frame buffer. Returns nothing.
void setDimensions(int width, int height, int depth)
{
    Width = width;
    Height = height;
    Depth = depth;

    FrameBufferSize = Width * Height * Depth;
}

// setActiveFrameBuffer takes the given index and sets it to the active index. Returns nothing.
void setActiveFrameBuffer(int idx)
{
    ActiveFrameBufferIdx = idx;
}

// initializeFlipQueue creates an event queue for sceVideo flip events. Returns error code.
int initializeFlipQueue(int video)
{
    // Create an event queue
    int rc = sceKernelCreateEqueue(&FlipQueue, "homebrew flip queue");

    if (rc < 0)
        return rc;

    // Unknown if we *have* to do this, but most ELFs seem to do this, so we'll do it too
    sceVideoOutAddFlipEvent(FlipQueue, video, 0);
    return rc;
}

// allocateVideoMem takes a given size and alignment, and allocates and maps direct memory and sets the VideoMem pointer to it.
// Returns error code.
int allocateVideoMem(size_t size, int alignment)
{
    int rc;

    // Align the allocation size
    DirectMemAllocationSize = (size + alignment - 1) / alignment * alignment;

    // Allocate memory for display buffer
    rc = sceKernelAllocateDirectMemory(0, sceKernelGetDirectMemorySize(), DirectMemAllocationSize, alignment, 3, &DirectMemOff);

    if (rc < 0)
    {
        DirectMemAllocationSize = 0;
        return rc;
    }

    // Map the direct memory
    rc = sceKernelMapDirectMemory(&VideoMem, DirectMemAllocationSize, 0x33, 0, DirectMemOff, alignment);

    if (rc < 0)
    {
        sceKernelReleaseDirectMemory(DirectMemOff, DirectMemAllocationSize);

        DirectMemOff = 0;
        DirectMemAllocationSize = 0;

        return rc;
    }

    // Set the stack pointer to the beginning of the buffer
    VideoMemSP = (uintptr_t)VideoMem;

    return rc;
}

// deallocateVideoMem is a function to be called upon error, and it'll free the mapped direct memory, zero out meta-data, and
// free the FrameBuffer array. Returns nothing.
void deallocateVideoMem()
{
    // Free the direct memory
    sceKernelReleaseDirectMemory(DirectMemOff, DirectMemAllocationSize);

    // Zero out meta data
    VideoMem = 0;
    VideoMemSP = 0;
    DirectMemOff = 0;
    DirectMemAllocationSize = 0;

    // Free the frame buffer array
    free(FrameBuffers);
    FrameBuffers = 0;
}

// allocateFrameBuffer takes a given video handle and number of frames, and allocates an array with the give number of frames
// for the FrameBuffers, and also sets the attributes for the video handle. Finally, it registers the buffers to the handle
// before returning. Returns error code.
int allocateFrameBuffers(int video, int num)
{
    // Allocate frame buffers array
    FrameBuffers = (void **)calloc(num, sizeof(void *));

    // Set the display buffers
    for (int i = 0; i < num; i++)
        FrameBuffers[i] = allocDisplayMem(FrameBufferSize);

    // Set SRGB pixel format
    sceVideoOutSetBufferAttribute(&Attr, 0x80000000, 1, 0, Width, Height, Width);

    FrameBufferCount = num;

    // Register the buffers to the video handle
    return sceVideoOutRegisterBuffers(video, 0, FrameBuffers, num, &Attr);
}

// allocDisplayMem is essentially a bump allocator, which will allocate space off of VideoMem for FrameBuffers. Returns a pointer
// to the chunk requested.
void *allocDisplayMem(size_t sz)
{
    // Essentially just bump allocation
    void *allocatedPtr = (void *)VideoMemSP;
    VideoMemSP += sz;

    return allocatedPtr;
}

// frameBufferSwap swaps the ActiveFrameBufferIdx. Should be called at the end of every draw loop iteration. Returns nothing.
void frameBufferSwap()
{
    // Swap the frame buffer for some perf
    ActiveFrameBufferIdx = ActiveFrameBufferIdx + 1 % (FrameBufferCount - 1);
}

// frameBufferClear fills the frame buffer with white pixels. Returns nothing.
void frameBufferClear()
{
    // Clear the screen with a white frame buffer
    Color blank = { 255, 255, 255 };
    frameBufferFill(blank);
}

// frameBufferFill fills the frame buffer with pixels of the given red, green, and blue values. Returns nothing.
void frameBufferFill(Color color)
{
    drawRectangle(0, 0, Width, Height, color);
}

// frameWait waits on the event queue before swapping buffers
void frameWait(int video, int frameID)
{
    OrbisKernelEvent evt;
    int count;

    // If the video handle is not initialized, bail out. This is mostly a failsafe, this should never happen.
    if (video == 0)
        return;

    for (;;)
    {
        OrbisVideoOutFlipStatus flipStatus;

        // Get the flip status and check the arg for the given frame ID
        sceVideoOutGetFlipStatus(video, &flipStatus);

        if (flipStatus.flipArg == frameID)
            break;

        // Wait on next flip event
        if (sceKernelWaitEqueue(FlipQueue, &evt, 1, &count, 0) != 0)
            break;
    }
}

// drawPixel draws the given color to the given x-y coordinates in the frame buffer. Returns nothing.
void drawPixel(int x, int y, Color color)
{
    // Get pixel location based on pitch
    int pixel = (y * Width) + x;

    // Encode to 24-bit color
    uint32_t encodedColor = 0x80000000 + (color.r << 16) + (color.g << 8) + color.b;

    // Draw to the frame buffer
    ((uint32_t *)FrameBuffers[ActiveFrameBufferIdx])[pixel] = encodedColor;
}

// drawRectangle draws a rectangle at the given x-y xoordinates with the given width, height, and color to the frame
// buffer. Returns nothing.
void drawRectangle(int x, int y, int width, int height, Color color)
{
    int xPos, yPos;

    // Draw row-by-row, column-by-column
    for (yPos = y; yPos < y + height; yPos++)
    {
        for (xPos = x; xPos < x + width; xPos++)
        {
            drawPixel(xPos, yPos, color);
        }
    }
}
