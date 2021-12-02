#include <sstream>
#include <iostream>
#include <orbis/libkernel.h>
#include <orbis/UserService.h>

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
    
    int userID;
    char username[32];
    
    // Get the user ID + username
    OrbisUserServiceInitializeParams param;
    param.priority = ORBIS_KERNEL_PRIO_FIFO_LOWEST;
    sceUserServiceInitialize(&param);
    sceUserServiceGetInitialUser(&userID);

    (void)memset(username, 0, sizeof(username));

    if (sceUserServiceGetUserName(userID, username, sizeof(username) - 1) < 0)
    {
        DEBUGLOG << "Failed to get username!";
        return -1;
    }
    
    std::stringstream userTextStream;
    userTextStream << "Logged into: " << username << " (ID: 0x" << std::hex << userID << ")";
    
    DEBUGLOG << "Entering draw loop...";

    // Draw loop
    for (;;)
    {
        scene->DrawText((char *)userTextStream.str().c_str(), fontTxt, 150, 150, bgColor, fgColor);

        // Submit the frame buffer
        scene->SubmitFlip(frameID);
        scene->FrameWait(frameID);

        // Swap to the next buffer
        scene->FrameBufferSwap();
        frameID++;
    }

    return 0;
}

