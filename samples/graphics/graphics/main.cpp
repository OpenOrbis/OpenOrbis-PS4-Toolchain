#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <math.h>

#include "../../_common/graphics.h"
#include "../../_common/log.h"

// Dimensions
#define FRAME_WIDTH     1920
#define FRAME_HEIGHT    1080
#define FRAME_DEPTH        4

// Logging
std::stringstream debugLogStream;

int frameID = 0;

// drawMandelbrot runs the Mandelbrot algorithm and draws pixels to the frame buffer accordingly. Returns nothing, called every loop iteration.
void drawMandelbrot(Scene2D *scene)
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
            scene->DrawPixel(iX, iY, pixelColor);
        }
    }
}

int main()
{
    int rc;
    int video;
    int curFrame = 0;
    void *surfaceBuff = 0;

    // No buffering
    setvbuf(stdout, NULL, _IONBF, 0);
    
    // Create a 2D scene
    DEBUGLOG << "Creating a scene";
    
    auto scene = new Scene2D(FRAME_WIDTH, FRAME_HEIGHT, FRAME_DEPTH);
    
    if(!scene->Init(0xC000000, 2))
    {
    	DEBUGLOG << "Failed to initialize 2D scene";
    	for(;;);
    }

    scene->FrameBufferClear();
    
    DEBUGLOG << "Entering draw loop...";

    // Draw loop
    for (;;)
    {
        // Draw the mandelbrot
        drawMandelbrot(scene);

        // Submit the frame buffer
        scene->SubmitFlip(frameID);
        scene->FrameWait(frameID);

        // Swap to the next buffer
        scene->FrameBufferSwap();
        frameID++;
    }

    return 0;
}
