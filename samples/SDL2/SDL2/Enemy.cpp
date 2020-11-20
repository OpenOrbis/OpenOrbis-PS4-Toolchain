#include "Enemy.h"

Enemy::Enemy(SDL_Renderer* renderer, DifficultySpeedModifier difficultyLevel)
{
    // Load the ship texture
    SDL_Surface* shipSurface = IMG_Load("/app0/assets/images/enemy.tga");
    this->texture = SDL_CreateTextureFromSurface(renderer, shipSurface);

    // Default x and y
    this->currentDest.x = 50;
    this->currentDest.y = 50;

    this->trackingSlope  = 0;
    this->trackingOffset = 0;

    this->hitTarget = false;

    // Set the movement speed based on current difficulty
    switch (difficultyLevel)
    {
    case LEVEL_ZERO:
        this->moveSpeed = 0.10;
        break;
    case LEVEL_ONE:
        this->moveSpeed = 0.15;
        break;
    case LEVEL_TWO:
        this->moveSpeed = 0.20;
        break;
    case LEVEL_THREE:
        this->moveSpeed = 0.30;
        break;
    case LEVEL_FOUR:
        this->moveSpeed = 0.45;
        break;
    case LEVEL_FIVE:
        this->moveSpeed = 0.60;
        break;
    default:
        this->moveSpeed = 0.15;
        break;
    }
}

Enemy::~Enemy()
{
    // Destroy all textures
    if (this->texture != nullptr)
    {
        SDL_DestroyTexture(this->texture);
        this->texture = nullptr;
    }
}

void Enemy::Render(SDL_Renderer* renderer)
{
    if (this->texture != nullptr)
    {
        SDL_QueryTexture(this->texture, NULL, NULL, &this->currentDest.w, &this->currentDest.h);
        SDL_RenderCopyEx(renderer, this->texture, NULL, &this->currentDest, this->enemyOrientation, NULL, SDL_FLIP_NONE);
    }
}

void Enemy::Update(SDL_Renderer* renderer, int deltaFrameTicks, int totalFrameCount)
{
    float x;
    float y;

    // Avoid updating if the enemy reaches the player. We'll check by seeing if the enemy is within 10 pixels.
    if (abs(this->currentDest.x - this->targetDest.x) < 10 &&
        abs(this->currentDest.y - this->targetDest.y) < 10)
    {
        this->hitTarget = true;
        return;
    }

    // If we're to the left of the player, we need to move in the positive direction
    // If we're to the right of the player, we need to move in the negative direction
    int directionalModifier = 1;

    if (this->targetDest.x < this->currentDest.x)
        directionalModifier = -1;
    
    // x = x + step
    x = this->currentDest.x + ((this->moveSpeed * deltaFrameTicks) * directionalModifier);

    // y = mx + b
    y = (this->trackingSlope * x) + this->trackingOffset;

    this->currentDest.x = (int)x;
    this->currentDest.y = (int)y;
}

void Enemy::SetLocationAndTarget(int locationX, int locationY, int targetX, int targetY)
{
    this->currentDest.x = locationX;
    this->currentDest.y = locationY;

    this->targetDest.x = targetX;
    this->targetDest.y = targetY;

    // Solve for the slope and offset of the line
    float a = targetY - locationY;
    float b = locationX - targetX;
    float c = a * (locationX) + b * (locationY);

    this->trackingSlope  = (a * -1) / b;
    this->trackingOffset = (c / b);
}

void Enemy::SetOrientation(int degrees)
{
    this->enemyOrientation = degrees;
}

bool Enemy::CheckHitTarget()
{
    return this->hitTarget;
}

std::tuple<int, int> Enemy::GetEnemyLocation()
{
    int x = 0;
    int y = 0;

    if (this->texture != nullptr)
    {
        x = this->currentDest.x;
        y = this->currentDest.y;
    }

    return std::make_tuple(x, y);
}
