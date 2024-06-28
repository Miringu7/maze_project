#include "../inc/main.h"

void redrawScreen(float frameTime, SDL_Renderer *gRenderer, TTF_Font *gFont)
{
    // castRays(gRenderer);
    // renderFPS(frameTime, gRenderer, gFont);
    // SDL_RenderPresent(gRenderer);
    // SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
    // SDL_RenderClear(gRenderer);

    // Clear the renderer with the sky color
    SDL_SetRenderDrawColor(gRenderer, COLOR_SKY.r, COLOR_SKY.g, COLOR_SKY.b, 255);
    SDL_RenderClear(gRenderer);

    // Draw ground
    SDL_SetRenderDrawColor(gRenderer, COLOR_GROUND.r, COLOR_GROUND.g, COLOR_GROUND.b, 255);
    SDL_Rect groundRect = {0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2};
    SDL_RenderFillRect(gRenderer, &groundRect);

    // Cast rays and render walls
    castRays(gRenderer);
    // updateCameraPosition(moveSpeed, worldMap);

    // Render FPS
    renderFPS(frameTime, gRenderer, gFont);

    // draw minimap
    drawMinimap(gRenderer);

    // Present everything
    SDL_RenderPresent(gRenderer);
}
