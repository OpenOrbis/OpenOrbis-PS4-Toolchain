#include <sstream>

#include "../../_common/graphics.h"
#include "../../_common/log.h"
#include "keyboard.h"

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
    
    // Create a keyboard
    DEBUGLOG << "Initializing controller";
    
    auto keyboard = new Keyboard();
    
    if(!keyboard->Init(-1))
    {
    	DEBUGLOG << "Failed to initialize keyboard";
    	for(;;);
    }
    
    // Create PNG instances for all the sprites
    DEBUGLOG << "Entering draw loop...";

    Color black = {0, 0, 0};
    Color white = {255, 255, 255};

    // Load font
    FT_Face font;
    if(!scene->InitFont(&font, "/app0/font.ttf", 30))
    {
        DEBUGLOG << "Failed to load font";
        for(;;);
    }
    
    // Draw loop
    for (;;)
    {
        // Clear screen
        scene->DrawRectangle(0, 0, FRAME_WIDTH, FRAME_HEIGHT, black);

        // Display stats
        int lineno = 0;
        #define PRINT(s) scene->DrawText((char*)(s), font, 0, 35 + 40 * (lineno++), black, white)
        PRINT("Pressed keys:");
        for(uint16_t keyCode : keyboard->Keys())
        {
            int charCode = keyboard->Key2Char(keyCode);
            std::ostringstream line;
            if(charCode == '\b')
                line << "'\\b'";
            else if(charCode == '\t')
                line << "'\\t'";
            else if(charCode == '\n')
                line << "'\\n'";
            else if(charCode == '\\')
                line << "'\\\\'";
            else if(charCode == '\'')
                line << "'\\\''";
            else if(charCode >= 0)
                line << "'" << (char)charCode << "'";
            else
                line << "<keycode " << keyCode << ">";
            PRINT(line.str().c_str());
        }
        PRINT("Modifier keys:");
        if(keyboard->CheckModifierKey(Keyboard::ModifierKey::LEFT_SHIFT))
            PRINT("Left Shift");
        if(keyboard->CheckModifierKey(Keyboard::ModifierKey::LEFT_CTRL))
            PRINT("Left Control");
        if(keyboard->CheckModifierKey(Keyboard::ModifierKey::LEFT_ALT))
            PRINT("Left Alt");
        if(keyboard->CheckModifierKey(Keyboard::ModifierKey::LEFT_META))
            PRINT("Left Meta");
        if(keyboard->CheckModifierKey(Keyboard::ModifierKey::RIGHT_SHIFT))
            PRINT("Right Shift");
        if(keyboard->CheckModifierKey(Keyboard::ModifierKey::RIGHT_CTRL))
            PRINT("Right Control");
        if(keyboard->CheckModifierKey(Keyboard::ModifierKey::RIGHT_ALT))
            PRINT("Right Alt");
        if(keyboard->CheckModifierKey(Keyboard::ModifierKey::RIGHT_META))
            PRINT("Right Meta");
        PRINT("Locked keys:");
        if(keyboard->CheckLock(Keyboard::LockKey::NUM_LOCK))
            PRINT("Num Lock");
        if(keyboard->CheckLock(Keyboard::LockKey::CAPS_LOCK))
            PRINT("Caps Lock");
        if(keyboard->CheckLock(Keyboard::LockKey::SCROLL_LOCK))
            PRINT("Scroll Lock");
        #undef PRINT
        
        // Submit the frame buffer
        scene->SubmitFlip(frameID);
        scene->FrameWait(frameID);

        // Swap to the next buffer
        scene->FrameBufferSwap();
        frameID++;
    }
}
