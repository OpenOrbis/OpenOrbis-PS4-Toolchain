#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <math.h>

#include <orbis/Sysmodule.h>

#include "graphics.h"

// Dimensions
#define FRAME_WIDTH     1920
#define FRAME_HEIGHT    1080
#define FRAME_DEPTH        4

// Font information
#define FONT_SIZE_LARGE  128
#define FONT_SIZE_SMALL   64

// Background and foreground colors
Color bgColor;
Color fgColor;

// Font faces
FT_Face fontLarge;
FT_Face fontSmall;

int main()
{
    int rc;
    int video;
    int curFrame = 0;

    // Set colors
    bgColor = { 0, 0, 0 };
    fgColor = { 255, 255, 255 };

    // Load freetype
    rc = sceSysmoduleLoadModule(0x009A);

    if (rc < 0)
    {
        printf("[ERROR] Failed to load freetype module\n");
        return rc;
    }

    // Initialize freetype
    rc = FT_Init_FreeType(&ftLib);

    if (rc != 0)
    {
        printf("[ERROR] Failed to initialize freetypee\n");
        return rc;
    }

    // Initialize the font faces with arial (must be included in the package root!)
    const char *font = "/app0/arial.ttf";

    rc = initFont(&fontLarge, font, FONT_SIZE_LARGE);

    if (rc != 0)
    {
        printf("[ERROR] Failed to initialize font '%s'\n", font);
        return rc;
    }

    rc = initFont(&fontSmall, font, FONT_SIZE_SMALL);

    if (rc != 0)
    {
        printf("[ERROR] Failed to initialize freetype\n");
        return rc;
    }

    // Open a handle to video out
    video = sceVideoOutOpen(ORBIS_VIDEO_USER_MAIN, ORBIS_VIDEO_OUT_BUS_MAIN, 0, 0);

    if (video < 0)
    {
        printf("[ERROR] Failed to open a video out handle\n");
        return video;
    }

    // Create a queue for flip events
    if (initializeFlipQueue(video) < 0)
    {
        sceVideoOutClose(video);

        printf("[ERROR] Failed to create an event queue\n");
        return rc;
    }

    setDimensions(FRAME_WIDTH, FRAME_HEIGHT, FRAME_DEPTH);

    // Allocate direct memory for the frame buffers
    rc = allocateVideoMem(0xC000000, 0x200000);

    if (rc < 0)
    {
        sceVideoOutClose(video);

        printf("[ERROR] Failed to allocate video memory\n");
        return rc;
    }

    // Set the frame buffers
    rc = allocateFrameBuffers(video, 2);

    if (rc < 0)
    {
        deallocateVideoMem();
        sceVideoOutClose(video);

        printf("[ERROR] Failed to allocate frame buffers from video memory\n");
        return rc;
    }

    setActiveFrameBuffer(0);

    // Set the flip rate
    sceVideoOutSetFlipRate(video, 0);

    // Blacken the background (easier on the eyes)
    frameBufferFill(bgColor);

    // Draw loop
    for (;;)
    {
        int frameID = curFrame ^ 1;

        // Draw the sample text
        const char *textLarge = "OpenOrbis Sample\nHello, World!";
        const char *textSmall = "Built with the OpenOrbis toolchain...";
        const char *textWrapContent = "text wrapping example, it breaks line based on width of container";
        
        drawText((char *)textLarge, fontLarge, 150, 400, bgColor, fgColor);
        drawText((char *)textSmall, fontSmall, 150, 750, bgColor, fgColor);
        drawTextContainer((char *)textWrapContent, fontSmall, 0, 0, 500, 300, bgColor, fgColor);
        
        // Submit the frame buffer
        sceVideoOutSubmitFlip(video, ActiveFrameBufferIdx, ORBIS_VIDEO_OUT_FLIP_VSYNC, curFrame);
        frameWait(video, curFrame);

        // Swap to the next buffer
        frameBufferSwap();
        curFrame = frameID;
    }

    return 0;
}
