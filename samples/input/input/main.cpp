#include <sstream>

#include "../../_common/graphics.h"
#include "../../_common/png.h"
#include "../../_common/log.h"
#include "controller.h"

// Dimensions
#define FRAME_WIDTH     1920
#define FRAME_HEIGHT    1080
#define FRAME_DEPTH        4

// Logging
std::stringstream debugLogStream;

int frameID = 0;
Color bgColor;

int main(void)
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
    
    // Create a controller
    DEBUGLOG << "Initializing controller";
    
    auto controller = new Controller();
    
    if(!controller->Init(-1))
    {
    	DEBUGLOG << "Failed to initialize controller";
    	for(;;);
    }
    
    // Create PNG instances for all the sprites
    auto controllerBackground = new PNG("/app0/assets/images/controller.png");
    auto thumbstick = new PNG("/app0/assets/images/thumbstick.png");
    auto touchpad = new PNG("/app0/assets/images/touchpad.png");
    auto dpadUp = new PNG("/app0/assets/images/dpad-up.png");
    auto dpadRight = new PNG("/app0/assets/images/dpad-right.png");
    auto dpadDown = new PNG("/app0/assets/images/dpad-down.png");
    auto dpadLeft = new PNG("/app0/assets/images/dpad-left.png");
    auto triangleBtn = new PNG("/app0/assets/images/triangle.png");
    auto circleBtn = new PNG("/app0/assets/images/circle.png");
    auto xBtn = new PNG("/app0/assets/images/x.png");
    auto squareBtn = new PNG("/app0/assets/images/square.png");
    auto startBtn = new PNG("/app0/assets/images/start.png");
    auto l1Trigger = new PNG("/app0/assets/images/l1.png");
    auto l2Trigger = new PNG("/app0/assets/images/l2.png");
    auto r1Trigger = new PNG("/app0/assets/images/r1.png");
    auto r2Trigger = new PNG("/app0/assets/images/r2.png");

    DEBUGLOG << "Entering draw loop...";
    
    // Draw loop
    for (;;)
    {
        controllerBackground->Draw(scene, 0, 0);
    	
        if(controller->TrianglePressed())
        {
        	triangleBtn->Draw(scene, 1187, 359);
        }
        
        if(controller->CirclePressed())
        {
        	circleBtn->Draw(scene, 1244, 416);
        }
        
        if(controller->XPressed())
        {
        	xBtn->Draw(scene, 1187, 472);
        }
        
        if(controller->SquarePressed())
        {
        	squareBtn->Draw(scene, 1131, 416);
        }
        
        if(controller->L1Pressed())
        {
        	l1Trigger->Draw(scene, 653, 139);
        }
        
        if(controller->L2Pressed())
        {
        	l2Trigger->Draw(scene, 653, 181);
        }
        
        if(controller->R1Pressed())
        {
        	r1Trigger->Draw(scene, 1150, 139);
        }
        
        if(controller->R2Pressed())
        {
        	r2Trigger->Draw(scene, 1150, 181);
        }
        
        if(controller->L3Pressed())
        {
        	thumbstick->Draw(scene, 780, 516);
        }
        
        if(controller->R3Pressed())
        {
        	thumbstick->Draw(scene, 1037, 516);
        }
        
        if(controller->StartPressed())
        {
        	startBtn->Draw(scene, 1094, 334);
        }
        
        if(controller->DpadUpPressed())
        {
        	dpadUp->Draw(scene, 687, 377);
        }
        
	if(controller->DpadRightPressed())
        {
        	dpadRight->Draw(scene, 722, 422);
        }
        
        if(controller->DpadDownPressed())
        {
        	dpadDown->Draw(scene, 687, 458);
        }
        
        if(controller->DpadLeftPressed())
        {
        	dpadLeft->Draw(scene, 641, 422);
        }
        
        if(controller->TouchpadPressed())
        {
        	touchpad->Draw(scene, 854, 323);
        }

        // Submit the frame buffer
        scene->SubmitFlip(frameID);
        scene->FrameWait(frameID);

        // Swap to the next buffer
        scene->FrameBufferSwap();
        frameID++;
    }
}
