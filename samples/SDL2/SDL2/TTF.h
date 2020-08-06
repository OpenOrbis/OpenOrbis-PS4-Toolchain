#pragma once

#include <proto-include.h>

#include "Game.h"

extern FT_Library ftLib;

bool InitFont(FT_Face* face, const char* fontPath, int fontSize);
int SetText(SDL_Surface* surface, char* txt, FT_Face face, Color fgColor, Color bgColor);
SDL_Texture* CreateText(SDL_Renderer* renderer, char* txt, FT_Face fontFace, Color fgColor, Color bgColor);
