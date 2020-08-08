#pragma once

#include <tuple>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Player
{
private:
    SDL_Texture* texture;
    SDL_Rect dest;

    int orientation;

public:
    Player(SDL_Renderer *renderer);
    ~Player();

    void Render(SDL_Renderer* renderer);
    // No update handler

    void SetTrajectory(int degrees);

    std::tuple<int, int> GetShipLocation();
    int GetTrajectory();
};
