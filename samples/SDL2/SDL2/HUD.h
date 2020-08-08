#pragma once

#include <string>
#include <SDL2/SDL.h>

#include "Color.h"
#include "TTF.h"

class HUD
{
private:
	SDL_Texture* scoreTexture;
	SDL_Texture* fpsCounterTexture;
	SDL_Texture* mspfCounterTexture;
	SDL_Texture* frameCounterTexture;
	SDL_Texture* memCounterTexture;
	SDL_Texture* gameOverHeaderTexture;
	SDL_Texture* gameOverRestartTexture;

	SDL_Rect scoreCounterDest;
	SDL_Rect fpsCounterDest;
	SDL_Rect mspfCounterDest;
	SDL_Rect frameCounterDest;
	SDL_Rect memCounterDest;
	SDL_Rect gameOverHeaderDest;
	SDL_Rect gameOverRestartDest;

	std::string scoreCounterText;
	std::string fpsCounterText;
	std::string mspfCounterText;
	std::string frameCounterText;
	std::string memCounterText;

	int score;
	bool updateScoreText;
	bool gameOver;

	Color bgColor;
	Color fgColor;

public:
	HUD();
	~HUD();

	void Render(SDL_Renderer* renderer);
	void Update(SDL_Renderer* renderer, int deltaFrameTicks, int totalFrameCount, bool gameOver);

	void SetScore(int score, std::string difficulty);
	void SetColorInfo(Color fg, Color bg);
};
