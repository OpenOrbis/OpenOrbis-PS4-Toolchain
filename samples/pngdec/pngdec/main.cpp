#include <sstream>

#include "../../_common/graphics.h"
#include "../../_common/png.h"
#include "../../_common/log.h"

// Dimensions
#define FRAME_WIDTH     1920
#define FRAME_HEIGHT    1080
#define FRAME_DEPTH        4

// Logging
std::stringstream debugLogStream;

int frameID = 0;
Color bgColor;

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
    
    DEBUGLOG << "Entering draw loop...";

    // Center the toolchain logo
    int imagePosX = (FRAME_WIDTH / 2) - (530 / 2); // We have to subtract the image width / 2 since our anchor point is the top left
    int imagePosY = (FRAME_HEIGHT / 2) - (530 / 2); // We have to subtract the image height / 2 since our anchor point is the top left
    
    // Create the PNG instance for the logo
    auto logo = new PNG("/app0/assets/images/logo.png");

    // Draw loop
    for (;;)
    {
        logo->Draw(scene, imagePosX, imagePosY);
        
        // Submit the frame buffer
        scene->SubmitFlip(frameID);
        scene->FrameWait(frameID);

        // Swap to the next buffer
        scene->FrameBufferSwap();
        frameID++;
    }

    return 0;
}
