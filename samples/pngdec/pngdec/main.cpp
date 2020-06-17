#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <math.h>

#include "graphics.h"

// Dimensions
#define FRAME_WIDTH     1920
#define FRAME_HEIGHT    1080
#define FRAME_DEPTH        4

#define STBI_ASSERT(x)
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

Color bgColor;

void drawPNG(const char *imagePath, int startX, int startY)
{
    int width, height, channels;

    uint32_t *img = (uint32_t *)stbi_load(imagePath, &width, &height, &channels, STBI_rgb_alpha);

    if (img == NULL)
    {
        printf("[ERROR] Failed to load img: %s\n", stbi_failure_reason());
        return;
    }

    // Iterate the bitmap and draw the pixels
    for (int yPos = 0; yPos < height; yPos++)
    {
        for (int xPos = 0; xPos < width; xPos++)
        {
            // Decode the 32-bit color
            uint32_t encodedColor = img[(yPos * width) + xPos];

            // Get new pixel coordinates to account for start coordinates
            int x = startX + xPos;
            int y = startY + yPos;

            // Re-encode the color
            uint8_t r = (uint8_t)(encodedColor >> 0);
            uint8_t g = (uint8_t)(encodedColor >> 8);
            uint8_t b = (uint8_t)(encodedColor >> 16);

            Color color = { r, g, b };

            // Do some bounds checking to make sure the pixel is actually inside the frame buffer
            if (xPos < 0 || yPos < 0 || xPos >= width || yPos >= height)
                continue;

            drawPixel(x, y, color);
        }
    }

    stbi_image_free(img);
}

int main()
{
    int rc;
    int video;
    int curFrame = 0;
    void *surfaceBuff = 0;

    // No buffering
    setvbuf(stdout, NULL, _IONBF, 0);

    // Set colors
    bgColor = { 0, 0, 0 };

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
    rc = allocateVideoMem(0x4000000, 0x200000);

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

    frameBufferFill(bgColor);

    // Center the toolchain logo
    int imagePosX = (FRAME_WIDTH / 2) - (530 / 2); // We have to subtract the image width / 2 since our anchor point is the top left
    int imagePosY = (FRAME_HEIGHT / 2) - (530 / 2); // We have to subtract the image height / 2 since our anchor point is the top left

    printf("GOING INTO DRAW LOOP");

    // Draw loop
    for (;;)
    {
        int frameID = curFrame ^ 1;

        drawPNG("/app0/logo.png", imagePosX, imagePosY);
        sceVideoOutSubmitFlip(video, ActiveFrameBufferIdx, ORBIS_VIDEO_OUT_FLIP_VSYNC, curFrame);
        frameWait(video, curFrame);

        frameBufferSwap();

        curFrame = frameID;
    }

    return 0;
}
