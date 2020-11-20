#include <sstream>
#include <iostream>
#include <thread>
#include <mutex>
#include <orbis/libkernel.h>

#include "../../_common/graphics.h"
#include "../../_common/log.h"

// Dimensions
#define FRAME_WIDTH     1920
#define FRAME_HEIGHT    1080
#define FRAME_DEPTH        4

// Font information
#define FONT_SIZE   	   42

// Logging
std::stringstream debugLogStream;

// Background and foreground colors
Color bgColor;
Color fgColor;

// Font faces
FT_Face fontTxt;

int frameID = 0;

// Threading stuff
std::stringstream screenTextStream;
std::mutex mtx;

void threadedFunctionA()
{
    for (int count = 0; count < 10; count++)
    {
        mtx.lock();
        screenTextStream << "Thread A is running: " << count << "\n";
        mtx.unlock();

        sceKernelUsleep(2 * 100000);
    }
}

void threadedFunctionB()
{
    for (int count = 0; count < 10; count++)
    {
        mtx.lock();
        screenTextStream << "Thread B is running: " << count << "\n";
        mtx.unlock();

        sceKernelUsleep(2 * 100000);
    }
}

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

    if(!scene->InitFont(&fontTxt, font, FONT_SIZE))
    {
    	DEBUGLOG << "Failed to initialize font '" << font << "'";
    	for(;;);
    }

    DEBUGLOG << "Entering draw loop...";
    
    // Setup threads
    std::thread t1(threadedFunctionA);
    std::thread t2(threadedFunctionB);

    // Draw loop
    for (;;)
    {
        scene->DrawText((char *)screenTextStream.str().c_str(), fontTxt, 150, 150, bgColor, fgColor);

        // Submit the frame buffer
        scene->SubmitFlip(frameID);
        scene->FrameWait(frameID);

        // Swap to the next buffer
        scene->FrameBufferSwap();
        frameID++;
    }

    return 0;
}

