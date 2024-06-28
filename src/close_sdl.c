#include "../inc/main.h"

void closeSDL(SDL_Window *gWindow, SDL_Renderer *gRenderer, TTF_Font *gFont)
{
    if (gFont)
    {
        TTF_CloseFont(gFont);
        gFont = NULL;
    }

    if (gRenderer)
    {
        SDL_DestroyRenderer(gRenderer);
        gRenderer = NULL;
    }

    if (gWindow)
    {
        SDL_DestroyWindow(gWindow);
        gWindow = NULL;
    }

       TTF_Quit();
    SDL_Quit();
}