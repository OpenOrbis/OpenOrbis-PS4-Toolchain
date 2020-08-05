#pragma once

#include <tuple>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

enum DifficultySpeedModifier
{
    LEVEL_ZERO,  // 0.10
    LEVEL_ONE,   // 0.15
    LEVEL_TWO,   // 0.20
    LEVEL_THREE, // 0.30
    LEVEL_FOUR,  // 0.45
    LEVEL_FIVE   // 0.60
};

class Enemy
{
private:
    SDL_Texture* texture;
    SDL_Rect currentDest;
    SDL_Rect targetDest;

    float moveSpeed;
    float trackingSlope;
    float trackingOffset;

    int enemyOrientation;

    bool hitTarget;

public:
    Enemy(SDL_Renderer* renderer, DifficultySpeedModifier difficultyLevel);
    ~Enemy();

    void Render(SDL_Renderer* renderer);
    void Update(SDL_Renderer* renderer, int deltaFrameTicks, int totalFrameCount);

    void SetLocationAndTarget(int locationX, int locationY, int targetX, int targetY);
    void SetOrientation(int degrees);
    bool CheckHitTarget();

    std::tuple<int, int> GetEnemyLocation();
};
