#include "../inc/main.h"

void redrawScreen(float frameTime, SDL_Renderer *gRenderer, TTF_Font *gFont)
{
    castRays(gRenderer);
    renderFPS(frameTime, gRenderer, gFont);

    SDL_RenderPresent(gRenderer);

    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
    SDL_RenderClear(gRenderer);
}
