#pragma once

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Color.h"
#include "TTF.h"

#include "HUD.h"
#include "Player.h"
#include "Projectile.h"
#include "Enemy.h"

#define DIFFICULTY_LEVEL_ONE	"Normal"
#define DIFFICULTY_LEVEL_TWO	"Intermediate"
#define DIFFICULTY_LEVEL_THREE	"Hard"
#define DIFFICULTY_LEVEL_FOUR	"Very Hard"
#define DIFFICULTY_LEVEL_FIVE	"Death"

extern Color bgColor;
extern Color fgColor;

extern FT_Face fontDebug;
extern FT_Face fontScore;

extern SDL_Joystick* controller;

enum ControllerButton {
	PAD_BUTTON_CROSS		= 0,
	PAD_BUTTON_CIRCLE,
	PAD_BUTTON_SQUARE,
	PAD_BUTTON_TRIANGLE,
	PAD_BUTTON_L1,
	PAD_BUTTON_R1,
	PAD_BUTTON_OPTIONS		= 9,
	PAD_BUTTON_L3			= 11,
	PAD_BUTTON_R3,
	PAD_BUTTON_UP,
	PAD_BUTTON_DOWN,
	PAD_BUTTON_LEFT,
	PAD_BUTTON_RIGHT,
	PAD_BUTTON_TOUCH_PAD,
	PAD_BUTTON_L2,
	PAD_BUTTON_R2
};

void initGame(SDL_Renderer* renderer);
void render(SDL_Renderer* renderer);
void update(SDL_Renderer* renderer, int deltaFrameTicks, int totalFrameCount, int totalTickCount);
