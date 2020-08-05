#include "HUD.h"

#include <sys/resource.h>

HUD::HUD()
{
    // Initially the textures will be null, to be set by the update handler
    this->scoreTexture		    = nullptr;
    this->scoreTexture		    = nullptr;
    this->fpsCounterTexture	    = nullptr;
    this->mspfCounterTexture	= nullptr;
    this->frameCounterTexture   = nullptr;
    this->memCounterTexture	    = nullptr;

    // Score will be in the top left corner
    this->scoreCounterDest.x    = 20;
    this->scoreCounterDest.y    = 20;

    // FPS counter, ms/frame counter, frame counter, and memory usage counter will be small "debug" text in bottom left corner
    this->fpsCounterDest.x      = 20;
    this->fpsCounterDest.y      = 980;

    this->mspfCounterDest.x     = 20;
    this->mspfCounterDest.y     = 1000;

    this->frameCounterDest.x    = 20;
    this->frameCounterDest.y    = 1020;

    this->memCounterDest.x      = 20;
    this->memCounterDest.y      = 1040;

    // Default text
    this->scoreCounterText      = "Score: 0";
    this->fpsCounterText        = "FPS: -";
    this->mspfCounterText       = "Frame execution time:  -";
    this->frameCounterText      = "Total frames executed: -";
    this->memCounterText        = "Memory usage: -";

    // Score text will only be re-created when needed
    this->updateScoreText       = false;

    this->gameOver = false;
}

HUD::~HUD()
{
    // Destroy all textures
    if (this->scoreTexture != nullptr)
    {
        SDL_DestroyTexture(this->scoreTexture);
        this->scoreTexture = nullptr;
    }

    if (this->fpsCounterTexture != nullptr)
    {
        SDL_DestroyTexture(this->fpsCounterTexture);
        this->fpsCounterTexture = nullptr;
    }

    if (this->mspfCounterTexture != nullptr)
    {
        SDL_DestroyTexture(this->mspfCounterTexture);
        this->mspfCounterTexture = nullptr;
    }

    if (this->frameCounterTexture != nullptr)
    {
        SDL_DestroyTexture(this->frameCounterTexture);
        this->frameCounterTexture = nullptr;
    }

    if (this->memCounterTexture != nullptr)
    {
        SDL_DestroyTexture(this->memCounterTexture);
        this->memCounterTexture = nullptr;
    }
}

void HUD::Render(SDL_Renderer* renderer)
{
    // Render the score counter
    if (this->scoreTexture != nullptr)
    {
        SDL_QueryTexture(this->scoreTexture, NULL, NULL, &this->scoreCounterDest.w, &this->scoreCounterDest.h);
        SDL_RenderCopy(renderer, this->scoreTexture, NULL, &this->scoreCounterDest);
    }

    // Render the FPS counter
    if (this->fpsCounterTexture != nullptr)
    {
        SDL_QueryTexture(this->fpsCounterTexture, NULL, NULL, &this->fpsCounterDest.w, &this->fpsCounterDest.h);
        SDL_RenderCopy(renderer, this->fpsCounterTexture, NULL, &this->fpsCounterDest);
    }

    // Render the ms/frame counter
    if (this->mspfCounterTexture != nullptr)
    {
        SDL_QueryTexture(this->mspfCounterTexture, NULL, NULL, &this->mspfCounterDest.w, &this->mspfCounterDest.h);
        SDL_RenderCopy(renderer, this->mspfCounterTexture, NULL, &this->mspfCounterDest);
    }

    // Render the frame counter
    if (this->frameCounterTexture != nullptr)
    {
        SDL_QueryTexture(this->frameCounterTexture, NULL, NULL, &this->frameCounterDest.w, &this->frameCounterDest.h);
        SDL_RenderCopy(renderer, this->frameCounterTexture, NULL, &this->frameCounterDest);
    }

    // Render the memory tracker
    if (this->memCounterTexture != nullptr)
    {
        SDL_QueryTexture(this->memCounterTexture, NULL, NULL, &this->memCounterDest.w, &this->memCounterDest.h);
        SDL_RenderCopy(renderer, this->memCounterTexture, NULL, &this->memCounterDest);
    }

    // Render the game over textures if the game is over
    if (gameOver)
    {
        if (this->gameOverHeaderTexture != nullptr)
        {
            SDL_QueryTexture(this->gameOverHeaderTexture, NULL, NULL, &this->gameOverHeaderDest.w, &this->gameOverHeaderDest.h);

            // Center it
            this->gameOverHeaderDest.x = (1920 / 2) - 80;
            this->gameOverHeaderDest.y = (1080 / 2) - 40;

            SDL_RenderCopy(renderer, this->gameOverHeaderTexture, NULL, &this->gameOverHeaderDest);
        }

        if (this->gameOverRestartTexture != nullptr)
        {
            SDL_QueryTexture(this->gameOverRestartTexture, NULL, NULL, &this->gameOverRestartDest.w, &this->gameOverRestartDest.h);

            // Center it
            this->gameOverRestartDest.x = (1920 / 2) - 175;
            this->gameOverRestartDest.y = (1080 / 2);

            SDL_RenderCopy(renderer, this->gameOverRestartTexture, NULL, &this->gameOverRestartDest);
        }
    }
}

void HUD::Update(SDL_Renderer* renderer, int deltaFrameTicks, int totalFrameCount, bool gameOver)
{
    // Score text
    if (this->updateScoreText)
    {
        if (this->scoreTexture != nullptr)
            SDL_DestroyTexture(this->scoreTexture);

        this->scoreTexture = CreateText(renderer, (char*)scoreCounterText.c_str(), fontScore, this->fgColor, this->bgColor);

        // Wait for next score update
        this->updateScoreText = false;
    }

    // If the game is over, create the textures to show the game is over. If not, destroy the textures, because the game may
    // have restarted.
    if (gameOver)
    {
        if (this->gameOverHeaderTexture == nullptr)
            this->gameOverHeaderTexture = CreateText(renderer, "Game Over!", fontScore, this->fgColor, this->bgColor);

        if (this->gameOverRestartTexture == nullptr)
            this->gameOverRestartTexture = CreateText(renderer, "Press start to restart", fontScore, this->fgColor, this->bgColor);

        this->gameOver = true;
    }
    else
    {
        if (this->gameOverHeaderTexture != nullptr)
        {
            SDL_DestroyTexture(this->gameOverHeaderTexture);
            this->gameOverHeaderTexture = nullptr;
        }

        if (this->gameOverRestartTexture != nullptr)
        {
            SDL_DestroyTexture(this->gameOverRestartTexture);
            this->gameOverRestartTexture = nullptr;
        }

        gameOver = false;
    }

    // Debug text (only updated every 10 frames)
    frameCounterText = "Total frames executed: " + std::to_string(totalFrameCount);

    if (totalFrameCount % 10 == 0)
    {
        // Calculate FPS and ms/frame
        int fps = 1000 / (deltaFrameTicks);
        int mspf = deltaFrameTicks;

        // Probe for memory usage
        struct rusage resources;

        memset(&resources, 0, sizeof(resources));
        getrusage(RUSAGE_SELF, &resources);

        int memUsageInKb = resources.ru_maxrss;

        this->fpsCounterText  = "FPS: " + std::to_string(fps);
        this->mspfCounterText = "Frame execution time:  " + std::to_string(mspf) + "ms";
        this->memCounterText  = "Memory usage: " + std::to_string(memUsageInKb) + "kb (" + std::to_string(memUsageInKb / 1000) + "mb)";

        // FPS counter
        if (this->fpsCounterTexture != nullptr)
            SDL_DestroyTexture(this->fpsCounterTexture);

        this->fpsCounterTexture = CreateText(renderer, (char*)this->fpsCounterText.c_str(), fontDebug, this->fgColor, this->bgColor);

        // Frame execution time counter
        if (this->mspfCounterTexture != nullptr)
            SDL_DestroyTexture(this->mspfCounterTexture);

        this->mspfCounterTexture = CreateText(renderer, (char*)this->mspfCounterText.c_str(), fontDebug, this->fgColor, this->bgColor);

        // Memory tracker
        if (this->memCounterTexture != nullptr)
            SDL_DestroyTexture(this->memCounterTexture);

        this->memCounterTexture = CreateText(renderer, (char*)this->memCounterText.c_str(), fontDebug, this->fgColor, this->bgColor);
    }

    // Frame counter
    if (this->frameCounterTexture != nullptr)
        SDL_DestroyTexture(this->frameCounterTexture);

    this->frameCounterTexture = CreateText(renderer, (char*)this->frameCounterText.c_str(), fontDebug, this->fgColor, this->bgColor);
}

void HUD::SetScore(int score, std::string difficulty)
{
    this->score = score;
    this->scoreCounterText = "Score: " + std::to_string(score) + " (Difficulty: " + difficulty + ")";
    this->updateScoreText  = true;
}

void HUD::SetColorInfo(Color fg, Color bg)
{
    this->fgColor = fg;
    this->bgColor = bg;
}
