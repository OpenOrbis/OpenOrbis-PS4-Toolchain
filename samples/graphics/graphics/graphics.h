#include <stdint.h>
#include <orbis/libkernel.h>
#include <orbis/VideoOut.h>

#ifndef GRAPHICS_H
#define GRAPHICS_H

// Color is used to pack together RGB information, and is used for every function that draws colored pixels.
typedef struct Color
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

// Pointer to direct video memory and the frame buffer array
extern void *VideoMem;
extern void **FrameBuffers;

// Points to the top of video memory, used for the bump allocator
extern uintptr_t VideoMemSP;

// Event queue for flips
extern OrbisKernelEqueue FlipQueue;

// Attributes for the frame buffers
extern OrbisVideoOutBufferAttribute Attr;

// Direct memory offset and allocation size
extern off_t DirectMemOff;
extern size_t DirectMemAllocationSize;

// Meta info for frame information
extern int Width;
extern int Height;
extern int Depth;

// Frame buffer size and count - initialized by allocateFrameBuffers()
extern int FrameBufferSize;
extern int FrameBufferCount;

// Active frame buffer for swapping
extern int ActiveFrameBufferIdx;

// Used for setting dimensions
void setDimensions(int width, int height, int depth);

void setActiveFrameBuffer(int idx);

// Initializes flip event queue and allocates video memory for frame buffers
int initializeFlipQueue(int video);
int allocateVideoMem(size_t size, int alignment);
void deallocateVideoMem();
int allocateFrameBuffers(int video, int num);

// Allocates display memory - bump allocator for video mem
void *allocDisplayMem(size_t sz);

// Frame buffer functions
void frameWait(int video, int frameID);
void frameBufferSwap();
void frameBufferClear();
void frameBufferFill(Color color);

// Draw functions
void drawPixel(int x, int y, Color color);
void drawRectangle(int x, int y, int width, int height, Color color);

#endif