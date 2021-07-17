#include <iostream>
#include "texture.h"
#include "utils/logging/logutils.h"

SDL_Texture* LoadTexture(const std::string& file, SDL_Renderer *ren)
{
    SDL_Texture *texture = nullptr;
    SDL_Surface *loadedImage = SDL_LoadBMP(file.c_str());
    if (loadedImage != nullptr)
    {
        texture = SDL_CreateTextureFromSurface(ren, loadedImage);
        SDL_FreeSurface(loadedImage);
        if (texture == nullptr)
        {
            LogUtils::LogSDLError(std::cout, "SDL_CreateTextureFromSurface");
        }
    } else
    {
        LogUtils::LogSDLError(std::cout, "SDL_LoadBMP");
    }

    return texture;
}

void RenderTexture(SDL_Texture * tex, SDL_Renderer * ren, int x, int y)
{
    SDL_Rect destination{};
    destination.x = x;
    destination.y = y;
    // query the texture to get it's width and height
    SDL_QueryTexture(tex, nullptr, nullptr, &destination.w, &destination.h);
    SDL_RenderCopy(ren, tex, nullptr, &destination);
}
