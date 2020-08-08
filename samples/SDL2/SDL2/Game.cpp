#include <tuple>
#include <cmath>
#include <vector>

#include <orbis/libkernel.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <time.h>

#include "Game.h"

// Font faces
FT_Face fontDebug;
FT_Face fontScore;

// Color info
Color bgColor = { 0x10, 0x10, 0x10 };
Color fgColor = { 255, 255, 255 };

// Controller / input
SDL_Joystick* controller;

// Input trackers
int lastLeftStickX = 0;
int lastLeftStickY = 0;

// Location trackers
int playerX = 0;
int playerY = 0;

// Tick trackers
int lastEnemySpawnTick = 0;

// Game meta information
DifficultySpeedModifier difficultyLevel = LEVEL_ZERO;
std::string difficultyDisplay = "Easy";
int currentScore = 0;
bool gameOver = false;

// Classes
HUD* hud;
Player* player;
std::vector<Enemy*> enemies;
std::vector<Projectile*> projectiles;

// Credit: Ryan Juckett
void applyCircularDeadZone(float* pOutX, float* pOutY, float x, float y, float low, float high)
{
    float mag = sqrtf(x * x + y * y);

    if (mag > low)
    {
        float legalRange    = 1.0f - high - low;
        float normalizedMag = fmin(1.0f, (mag - low) / legalRange);
        float scale = normalizedMag / mag;

        *pOutX = x * scale;
        *pOutY = y * scale;
    }
    else
    {
        // Deadzoned
        *pOutX = 0.0f;
        *pOutY = 0.0f;
    }
}

void handleControllerButtonPress(SDL_Renderer* renderer, SDL_Event* ev)
{
    switch (ev->jbutton.button)
    {
    // Shoot projectile
    case PAD_BUTTON_CROSS:
        {
            // Create the projectile and add it to the list
            Projectile* projectile = new Projectile(renderer);

            projectile->SetTrajectory(player->GetTrajectory());
            projectile->SetLocation(playerX, playerY);
            projectiles.push_back(projectile);
        }
        break;

    // Restart game
    case PAD_BUTTON_OPTIONS:
        {
            if (gameOver)
            {
                // Reset stats 
                currentScore = 0;
                difficultyLevel = LEVEL_ONE;
                difficultyDisplay = DIFFICULTY_LEVEL_ONE;

                hud->SetScore(currentScore, difficultyDisplay);

                // Destroy all current enemies and projectiles
                for (auto enemy : enemies)
                    delete enemy;

                enemies.clear();

                for (auto projectile : projectiles)
                    delete projectile;

                projectiles.clear();

                // Switch the game back on
                gameOver = false;
            }
        }
        break;
    }
}

void handleControllerAxisChange(SDL_Event* ev)
{
    double rotationAngle = 0;
    float rotateX = 0;
    float rotateY = 0;

    // Left stick = rotate
    if (ev->jaxis.axis == 0)
    {
        rotateX = (float)ev->jaxis.value / 32767.0f;
        rotateX *= -1;
    }

    if (ev->jaxis.axis == 1)
    {
        rotateY = (float)ev->jaxis.value / 32767.0f;
    }

    applyCircularDeadZone(&rotateX, &rotateY, rotateX, rotateY, 0.25f, 1.00f);

    // If both X and Y are 0, do not update
    if (rotateX == 0.0f && rotateY == 0.0f)
        return;

    // Default back on the last values if no update received for either axis
    if (rotateX == 0.0f)
        rotateX = lastLeftStickX;
    else
        lastLeftStickX = rotateX;
    
    if (rotateY == 0.0f)
        rotateY = lastLeftStickY;
    else
        lastLeftStickY = rotateY;

    // Calculate the angle to rotate in degrees (cw)
    rotationAngle = atan2(rotateX, rotateY) * (180.0f / M_PI);

    // We have to convert the rotation to cw from ccw if it's negative, because we cannot rotate ccw in SDL
    if (rotationAngle < 0)
        rotationAngle = 360 + rotationAngle; // rotationAngle is negative

    // Commit the ship rotation for rendering
    player->SetTrajectory((int)rotationAngle);
}

void spawnEnemy(SDL_Renderer* renderer)
{
    // Choose semi-random coordinates for the enemy
    // --
    // The enemies can only spawn near the edges of the screen, so we have to do some checks and balances on the generated
    // x and y coordinates. x can either be 50, (1920 - 50) = 1870, or a random value between those except right under or above the player,
    // however if x meets 50 < x < 1870 (860 !< x !< 1060), then y must be 100 or (1080 - 100) = 980. We also must evenly distribute x
    // between the three options or almost all the enemies will be exclusively at the top or bottom of the screen. We'll call this
    // the "section".
    //
    // Sections:
    //     0 = left
    //     1 = middle
    //     2 = right
    // Ranges:
    //    50 <= x <= 1870 (860 !< x !< 1060)
    //   100 <= y <= 980

    int enemyX;
    int enemyY;
    int section = rand() % 3;
    int top     = rand() % 1;

    // Give it a random orientation to make it more visually interesting
    int orientation = rand() % 360;

    switch (section)
    {
    case 0:
        enemyX = 50;
        enemyY = rand() % 980 + 100;
        break;
    case 1:
        // Keep generating values until we get one that fits the restriction
        do
        {
            enemyX = rand() % 1870 + 50;
        } while (enemyX > 860 && enemyX < 1060);

        if (top)
            enemyY = 100;
        else
            enemyY = 980;

        break;
    case 2:
        enemyX = 1870;
        enemyY = rand() % 980 + 100;
    }

    // Create the enemy and add it to the list
    Enemy* enemy = new Enemy(renderer, difficultyLevel);

    enemy->SetLocationAndTarget(enemyX, enemyY, playerX, playerY);
    enemy->SetOrientation(orientation);

    enemies.push_back(enemy);
}

void checkCollisionUpdates()
{
    std::vector<Projectile*>::iterator projectileIt;
    std::vector<Enemy*>::iterator enemyIt;

    // Check for Enemy -> Player collision
    for (auto it : enemies)
    {
        if (it->CheckHitTarget())
        {
            // Game over, no need to further process collisions
            gameOver = true;
            return;
        }
    }

    // Check for Projectile -> Enemy collision
    for (projectileIt = projectiles.begin(); projectileIt != projectiles.end();)
    {
        auto projectile = *projectileIt;
        auto projectileCoordinates = projectile->GetProjectileLocation();

        for (enemyIt = enemies.begin(); enemyIt != enemies.end();)
        {
            auto enemy = *enemyIt;
            auto enemyCoordinates = enemy->GetEnemyLocation();

            // We'll check for a collision within 96 / 2 pixels
            if (abs(std::get<0>(projectileCoordinates) - std::get<0>(enemyCoordinates)) < (96 / 2) &&
                abs(std::get<1>(projectileCoordinates) - std::get<1>(enemyCoordinates)) < (96 / 2))
            {
                // Increase score
                currentScore += 10;

                // Scale difficulty to score
                if (currentScore > 50)
                {
                    difficultyLevel = LEVEL_ONE;
                    difficultyDisplay = DIFFICULTY_LEVEL_ONE;
                }

                if (currentScore > 100)
                {
                    difficultyLevel = LEVEL_TWO;
                    difficultyDisplay = DIFFICULTY_LEVEL_TWO;
                }

                if (currentScore > 200)
                {
                    difficultyLevel = LEVEL_THREE;
                    difficultyDisplay = DIFFICULTY_LEVEL_THREE;
                }

                if (currentScore > 500)
                {
                    difficultyLevel = LEVEL_FOUR;
                    difficultyDisplay = DIFFICULTY_LEVEL_FOUR;
                }

                if (currentScore > 1000)
                {
                    difficultyLevel = LEVEL_FIVE;
                    difficultyDisplay = DIFFICULTY_LEVEL_FIVE;
                }

                hud->SetScore(currentScore, difficultyDisplay);

                // Destroy the enemy
                delete enemy;
                enemy = nullptr;

                enemyIt = enemies.erase(enemyIt);

                // Delete the projectile
                delete projectile;
                projectile = nullptr;

                projectileIt = projectiles.erase(projectileIt);

                // Do not process further because the entities are deleted
                break;
            }
            else
            {
                enemyIt++;
            }
        }

        // If the projectile was deleted due to collision, continue to the next projectile
        if (projectile == nullptr)
            continue;

        // Check for off-screen projectiles
        if (std::get<0>(projectileCoordinates) == -1 && std::get<1>(projectileCoordinates) == -1)
        {
            // Delete the projectile
            delete projectile;
            projectile = nullptr;

            projectileIt = projectiles.erase(projectileIt);
        }
        else
        {
            projectileIt++;
        }
    }
}

void render(SDL_Renderer* renderer)
{
    // Only render the player, enemies, and projectiles if the game is still going
    if (!gameOver)
    {
        // Player
        player->Render(renderer);

        // Enemies
        for (auto it : enemies)
            it->Render(renderer);

        // Projectiles
        for (auto it : projectiles)
            it->Render(renderer);
    }

    // Always render the HUD regardless
    hud->Render(renderer);
}

void update(SDL_Renderer *renderer, int deltaFrameTicks, int totalFrameCount, int totalTickCount)
{
    // Handle input
    SDL_Event ev;

    while (SDL_PollEvent(&ev) != 0)
    {
        // Button press
        if (ev.type == SDL_JOYBUTTONDOWN)
            handleControllerButtonPress(renderer, &ev);

        // Axis motion (left stick, right stick)
        if (ev.type == SDL_JOYAXISMOTION)
            handleControllerAxisChange(&ev);
    }

    // Handle enemy spawning, spawn a new enemy roughly every 800ms (if game is not over)
    if ((totalTickCount - lastEnemySpawnTick) >= 800 && !gameOver)
    {
        spawnEnemy(renderer);

        // Set next timeout
        lastEnemySpawnTick = totalTickCount;
    }

    // Run HUD updates
    hud->Update(renderer, deltaFrameTicks, totalFrameCount, gameOver);

    // Run game event updates
    if (!gameOver)
    {
        // Run enemy updates
        for (auto enemy : enemies)
            enemy->Update(renderer, deltaFrameTicks, totalFrameCount);

        // Run projectile update 
        for (auto projectile : projectiles)
            projectile->Update(renderer, deltaFrameTicks, totalFrameCount);

        // Check for collisions
        checkCollisionUpdates();
    }
}

void initGame(SDL_Renderer* renderer)
{
    // Seed RNG
    srand(time(0));

    // Initialize UI
    hud = new HUD();

    hud->SetColorInfo(fgColor, bgColor);
    hud->SetScore(0, DIFFICULTY_LEVEL_ONE);

    // Initialize the player / ship
    player = new Player(renderer);

    // Get the player location as coordinates and set the trackers
    auto playerLocation = player->GetShipLocation();
    playerX = std::get<0>(playerLocation);
    playerY = std::get<1>(playerLocation);
}
