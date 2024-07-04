#include "../inc/main.h"

/**
 * closeSDL - Cleans up SDL and TTF resources.
 * @gWindow: SDL window to destroy.
 * @gRenderer: SDL renderer to destroy.
 * @gFont: TTF font to close.
 *
 * This function safely cleans up SDL and TTF resources by destroying
 * the window, renderer, and closing the font. After cleanup, it quits
 * SDL and TTF subsystems.
 */
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
