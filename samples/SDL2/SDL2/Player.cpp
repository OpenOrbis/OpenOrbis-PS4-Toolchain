#include "Player.h"

Player::Player(SDL_Renderer *renderer)
{
    // Load the ship texture
    SDL_Surface* shipSurface = IMG_Load("/app0/assets/images/player.tga");
    this->texture = SDL_CreateTextureFromSurface(renderer, shipSurface);

    // Center the ship
    this->dest.x = (1920 / 2) - (shipSurface->w / 2);
    this->dest.y = (1080 / 2) - (shipSurface->h / 2);
}

Player::~Player()
{
    // Destroy all textures
    if (this->texture != nullptr)
    {
        SDL_DestroyTexture(this->texture);
        this->texture = nullptr;
    }
}

void Player::Render(SDL_Renderer* renderer)
{
    if (this->texture != nullptr)
    {
        SDL_QueryTexture(this->texture, NULL, NULL, &this->dest.w, &this->dest.h);
        SDL_RenderCopyEx(renderer, this->texture, NULL, &this->dest, this->orientation, NULL, SDL_FLIP_NONE);
    }
}

void Player::SetTrajectory(int degrees)
{
    this->orientation = degrees;
}

std::tuple<int, int> Player::GetShipLocation()
{
    return std::make_tuple(this->dest.x, this->dest.y);
}

int Player::GetTrajectory()
{
    return this->orientation;
}
