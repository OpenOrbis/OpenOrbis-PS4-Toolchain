#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <math.h>

#include "graphics.h"

// drawMandelbrot runs the Mandelbrot algorithm and draws pixels to the frame buffer accordingly. Returns nothing, called every loop iteration.
void drawMandelbrot()
{
    /* screen (integer) coordinate */
    int iX, iY;
    const int iXmax = 1920;
    const int iYmax = 1080;

    /* world ( double) coordinate = parameter plane*/
    double Cx, Cy;
    const double CxMin = -2.5;
    const double CxMax = 1.5;
    const double CyMin = -2.0;
    const double CyMax = 2.0;

    double PixelWidth = (CxMax - CxMin) / iXmax;
    double PixelHeight = (CyMax - CyMin) / iYmax;

    /* color component ( R or G or B) is coded from 0 to 255 */
    /* it is 24 bit color RGB file */
    const int MaxColorComponentValue = 255;

    static unsigned char color[3];

    /* Z=Zx+Zy*i  ;   Z0 = 0 */
    double Zx, Zy;
    double Zx2, Zy2; /* Zx2=Zx*Zx;  Zy2=Zy*Zy  */

    int Iteration;
    const int IterationMax = 255;

    /* bail-out value , radius of circle ;  */
    const double EscapeRadius = 2;
    double ER2 = EscapeRadius * EscapeRadius;

    /* compute and write image data bytes to the file*/
    for (iY = 0; iY < iYmax; iY++)
    {
        Cy = CyMin + iY * PixelHeight;
        if (fabs(Cy) < PixelHeight / 2) Cy = 0.0; /* Main antenna */

        for (iX = 0; iX < iXmax; iX++)
        {
            Cx = CxMin + iX * PixelWidth;

            /* initial value of orbit = critical point Z= 0 */
            Zx = 0.0;
            Zy = 0.0;
            Zx2 = Zx * Zx;
            Zy2 = Zy * Zy;

            for (Iteration = 0; Iteration < IterationMax && ((Zx2 + Zy2) < ER2); Iteration++)
            {
                Zy = 2 * Zx*Zy + Cy;
                Zx = Zx2 - Zy2 + Cx;
                Zx2 = Zx * Zx;
                Zy2 = Zy * Zy;
            };

            color[0] = 0;
            color[1] = 0;
            color[2] = 0;

            if (Iteration < 20)
                color[2] = (int)((255 * Iteration) / 20);

            Color pixelColor = { color[0], color[1], color[2] };
            drawPixel(iX, iY, pixelColor);
        }
    }
}

int main()
{
    int rc;
    int video;
    int curFrame = 0;
    void *surfaceBuff = 0;

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

    setDimensions(1920, 1080, 4);

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

    frameBufferClear();

    // Draw loop
    for (;;)
    {
        int frameID = curFrame ^ 1;

        drawMandelbrot();
        sceVideoOutSubmitFlip(video, ActiveFrameBufferIdx, ORBIS_VIDEO_OUT_FLIP_VSYNC, curFrame);
        frameWait(video, curFrame);

        frameBufferSwap();

        curFrame = frameID;
    }

    return 0;
}