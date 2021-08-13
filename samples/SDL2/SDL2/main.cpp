#include <sstream>
#include <orbis/libkernel.h>
#include <orbis/Sysmodule.h>

#include "Game.h"

#include "../../_common/log.h"

#define FRAME_WIDTH     1920
#define FRAME_HEIGHT    1080

// Logging
std::stringstream debugLogStream;

// SDL window and software renderer
SDL_Window* window;
SDL_Renderer* renderer;

// Frame tracking info for debugging
uint32_t lastFrameTicks  = 0;
uint32_t startFrameTicks = 0;
uint32_t deltaFrameTicks = 0;
uint32_t frameCounter    = 0;

// Debug trackers
uint32_t initialAvailableDirectMemory;

void SetCheckerboard(SDL_Surface* surface, int squareSize, Color colorA, Color colorB)
{
    Color curColor;

    int useForeground = 1;
    uint32_t* pixels = (uint32_t*)surface->pixels;

    for (int row = 0; row < surface->h; row += squareSize)
    {
        for (int col = 0; col < surface->w; col += squareSize)
        {
            if (useForeground)
            {
                curColor = colorB;
                useForeground = 0;
            }
            else
            {
                curColor = colorA;
                useForeground = 1;
            }

            for (int y = 0; y < squareSize; y++)
            {
                for (int x = 0; x < squareSize; x++)
                {
                    uint32_t pixel = ((row + y) * surface->w) + col + x;
                    pixels[pixel] = 0x80000000 + (curColor.r << 16) + (curColor.g << 8) + curColor.b;
                }
            }
        }

        // Swap colors each row
        if (useForeground)
            useForeground = 0;
        else
            useForeground = 1;
    }
}

int main(int argc, char* args[])
{
    int rc;
    SDL_Surface* windowSurface;

    // No buffering
    setvbuf(stdout, NULL, _IONBF, 0);

    // Initialize SDL functions
    DEBUGLOG << "Initializing SDL";

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) != 0)
    {
        DEBUGLOG << "Failed to initialize SDL: " << SDL_GetError();
        for (;;);
    }

    // We have to force load the freetype module or we'll get unresolved NID crashes
    DEBUGLOG << "Initializing TTF";

    rc = sceSysmoduleLoadModule(0x009A);

    if (rc < 0)
    {
        DEBUGLOG << "Failed to load freetype module: " << std::string(strerror(errno));
        for (;;);
    }

    // Finally initialize freetype
    rc = FT_Init_FreeType(&ftLib);

    if (rc < 0)
    {
        for (;;);
    }

    // Create a font face for debug and score text
    const char* debugFontPath = "/app0/assets/fonts/VeraMono.ttf";

    DEBUGLOG << "Initializing debug font (" << debugFontPath << ")";

    if (!InitFont(&fontDebug, debugFontPath, 16))
    {
        DEBUGLOG << "Failed to initialize debug font '" << debugFontPath << "'";
        for (;;);
    }

    const char* scoreFontPath = "/app0/assets/fonts/Bebas-Regular.ttf";

    DEBUGLOG << "Initializing score font (" << scoreFontPath << ")";

    if (!InitFont(&fontScore, scoreFontPath, 40))
    {
        DEBUGLOG << "Failed to initialize score font '" << scoreFontPath << "'";
        for (;;);
    }

    // Create a window context
    DEBUGLOG << "Creating a window";

    window = SDL_CreateWindow("main", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, FRAME_WIDTH, FRAME_HEIGHT, 0);

    if (!window)
    {
        DEBUGLOG << "Failed to create window: " << SDL_GetError();
        for (;;);
    }

    // Create a software rendering instance for the window
    windowSurface = SDL_GetWindowSurface(window);
    renderer = SDL_CreateSoftwareRenderer(windowSurface);

    if (!renderer)
    {
        DEBUGLOG << "Failed to create software renderer: " << SDL_GetError();
        for (;;);
    }

    // Initialize input / joystick
    if (SDL_NumJoysticks() < 1)
    {
        DEBUGLOG << "No controllers available!";
        for (;;);
    }

    controller = SDL_JoystickOpen(0);

    if (controller == NULL)
    {
        DEBUGLOG << "Couldn't open controller handle: " << SDL_GetError();
        for (;;);
    }

    initGame(renderer);

    // Enter the render loop
    DEBUGLOG << "Entering draw loop...";

    for (int frame = 0;; frame++)
    {
        startFrameTicks = SDL_GetTicks();
        deltaFrameTicks = startFrameTicks - lastFrameTicks;
        lastFrameTicks  = startFrameTicks;

        // Clear the canvas
        SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, 0xFF);
        SDL_RenderClear(renderer);

        // Run all rendering routines
        render(renderer);

        // Propagate the updated window to the screen
        SDL_UpdateWindowSurface(window);

        // Run all update routines
        update(renderer, deltaFrameTicks, frameCounter++, startFrameTicks);
    }

    SDL_Quit();
    return 0;
}
