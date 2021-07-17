#pragma once

#include "SDL.h"
#include <string>

SDL_Texture* LoadTexture(const std::string& file, SDL_Renderer *ren);
void RenderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);
