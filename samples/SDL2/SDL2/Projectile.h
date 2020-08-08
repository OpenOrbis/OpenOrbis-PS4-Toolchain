#pragma once

#include <tuple>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define PROJECTILE_SPEED 0.75f

class Projectile
{
private:
    SDL_Texture* texture;
    SDL_Rect currentDest;
    SDL_Rect targetDest;

    bool verticalSlope;
    float trackingSlope;
    float trackingOffset;

    int orientation;

public:
    Projectile(SDL_Renderer* renderer);
    ~Projectile();

    void Render(SDL_Renderer* renderer);
    void Update(SDL_Renderer* renderer, int deltaFrameTicks, int totalFrameCount);

    void SetLocation(int locationX, int locationY);
    void SetTrajectory(int degrees);

    std::tuple<int, int> GetProjectileLocation();
};
