#include "Projectile.h"

Projectile::Projectile(SDL_Renderer* renderer)
{
    // Load the ship texture
    SDL_Surface* projectileSurface = IMG_Load("/app0/assets/images/projectile.tga");
    this->texture = SDL_CreateTextureFromSurface(renderer, projectileSurface);

    this->targetDest.x = (1920 / 2) - projectileSurface->w;
    this->targetDest.y = (1080 / 2) - projectileSurface->h;

    this->verticalSlope = false;
}

Projectile::~Projectile()
{
    // Destroy all textures
    if (this->texture != nullptr)
    {
        SDL_DestroyTexture(this->texture);
        this->texture = nullptr;
    }
}

void Projectile::Render(SDL_Renderer* renderer)
{
    //SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
    //SDL_RenderDrawLine(renderer, this->projectileOriginX, this->projectileOriginY, this->targetDest.x, this->targetDest.y);

    if (this->texture != nullptr)
    {
        SDL_QueryTexture(this->texture, NULL, NULL, &this->currentDest.w, &this->currentDest.h);
        SDL_RenderCopyEx(renderer, this->texture, NULL, &this->currentDest, this->orientation, NULL, SDL_FLIP_NONE);
    }
}

void Projectile::Update(SDL_Renderer* renderer, int deltaFrameTicks, int totalFrameCount)
{
    float x;
    float y;

    int step = PROJECTILE_SPEED * deltaFrameTicks;

    // The projectile is deemed "off screen" if the top left anchor goes beyond the left, top, right, or bottom edges of the resolution
    int lowXY = 0 - 96;
    int highX = 1920 + 96;
    int highY = 1080 + 96;

    // If the projectile is off screen, destroy it and cease further updates
    if (this->currentDest.x < lowXY || this->currentDest.x > highX || this->currentDest.y < lowXY || this->currentDest.y > highY)
    {
        if (this->texture != nullptr)
        {
            SDL_DestroyTexture(this->texture);
            this->texture = nullptr;
        }

        return;
    }

    // If we're to the left or up of the player, we need to move in the positive direction
    // If we're to the right or down of the player, we need to move in the negative direction
    int xDirectionalModifier = 1;
    int yDirectionalModifier = 1;

    if (this->targetDest.x < this->currentDest.x)
        xDirectionalModifier = -1;

    if (this->targetDest.y < this->currentDest.y)
        yDirectionalModifier = -1;

    
    // Vertical lines *cannot have slopes* so:
    // vertical = false: x += step, y = mx + b
    // vertical = true:  x = x, y += step
    if (!this->verticalSlope)
    {
        x = this->currentDest.x + (step * xDirectionalModifier);
        y = (this->trackingSlope * x) + this->trackingOffset;
    }
    else
    {
        x = this->currentDest.x;
        y = this->currentDest.y + (step * yDirectionalModifier);
    }

    // Commit coordinate updates
    this->currentDest.x = (int)x;
    this->currentDest.y = (int)y;
}

void Projectile::SetLocation(int locationX, int locationY)
{
    // Set the target coordinates to 2000 away from the player at the trajectory the player is currently facing.
    // 
    // For X we'll use a cosine wave to calculate the final coordinate. We must convert the orientation in degrees to radians,
    // and shift the cosine wave by -90 degrees since 0 is up instead of right.
    // 
    // For Y we'll use a sine wave to calculate the final coordinate. Again, the orientation must be converted to radians, and a shift
    // of -90 degrees is necessary.
    float targetX = 2000 * cos((this->orientation * (M_PI / 180)) + (M_PI / -2)) + locationX;
    float targetY = 2000 * sin((this->orientation * (M_PI / 180)) + (M_PI / -2)) + locationY;

    this->currentDest.x = locationX;
    this->currentDest.y = locationY;

    this->targetDest.x = (int)targetX;
    this->targetDest.y = (int)targetY;

    // Solve for the slope and offset of the line
    float a = targetY - locationY;
    float b = locationX - targetX;
    float c = a * (locationX) + b * (locationY);

    // Slopes of "0" are technically impossible because you cannot divide by 0, so we'll track if we have a 0 slope to handle it differently.
    if (b == 0)
    {
        this->verticalSlope = true;
        return;
    }

    this->trackingSlope  = (a * -1) / b;
    this->trackingOffset = (c / b);
}

void Projectile::SetTrajectory(int degrees)
{
    this->orientation = degrees;
}

std::tuple<int, int> Projectile::GetProjectileLocation()
{
    // If the projectile is off screen, we'll indicate so with negative values
    int x = -1;
    int y = -1;

    if (this->texture != nullptr)
    {
        x = this->currentDest.x;
        y = this->currentDest.y;
    }
    
    return std::make_tuple(x, y);
}
