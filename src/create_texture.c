#include "../inc/main.h"

SDL_Texture *createTextureFromSurface(SDL_Renderer *renderer, SDL_Surface *surface)
{
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL)
    {
        fprintf(stderr, "Unable to create texture from surface! SDL Error: %s\n", SDL_GetError());
        SDL_FreeSurface(surface);
        return NULL;
    }
    return texture;
}

void renderTexture(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y)
{
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
    SDL_RenderCopy(renderer, texture, NULL, &dst);
}