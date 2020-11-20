#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <math.h>

#include <sstream>

#include "../../_common/graphics.h"
#include "../../_common/log.h"

// Dimensions
#define FRAME_WIDTH     1920
#define FRAME_HEIGHT    1080
#define FRAME_DEPTH        4

// Font information
#define FONT_SIZE_LARGE  128
#define FONT_SIZE_SMALL   64

// Logging
std::stringstream debugLogStream;

// Background and foreground colors
Color bgColor;
Color fgColor;

// Font faces
FT_Face fontLarge;
FT_Face fontSmall;

int frameID = 0;

int main()
{
    int rc;
    int video;
    int curFrame = 0;
    
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

    // Set colors
    bgColor = { 0, 0, 0 };
    fgColor = { 255, 255, 255 };

    // Initialize the font faces with arial (must be included in the package root!)
    const char *font = "/app0/assets/fonts/Gontserrat-Regular.ttf";
    
    DEBUGLOG << "Initializing font (" << font << ")";

    if(!scene->InitFont(&fontLarge, font, FONT_SIZE_LARGE))
    {
    	DEBUGLOG << "Failed to initialize large font '" << font << "'";
    	for(;;);
    }

    if(!scene->InitFont(&fontSmall, font, FONT_SIZE_SMALL))
    {
    	DEBUGLOG << "Failed to initialize small font '" << font << "'";
    	for(;;);
    }
    
    DEBUGLOG << "Entering draw loop...";

    // Draw loop
    for (;;)
    {
        // Draw the sample text
        const char *textLarge = "OpenOrbis Sample\nHello, World!";
        const char *textSmall = "Built with the OpenOrbis toolchain (in C++!)";
        
        scene->DrawText((char *)textLarge, fontLarge, 150, 400, bgColor, fgColor);
        scene->DrawText((char *)textSmall, fontSmall, 150, 750, bgColor, fgColor);

        // Submit the frame buffer
        scene->SubmitFlip(frameID);
        scene->FrameWait(frameID);

        // Swap to the next buffer
        scene->FrameBufferSwap();
        frameID++;
    }

    return 0;
}
