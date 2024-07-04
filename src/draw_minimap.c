#include "../inc/main.h"

/**
 * drawMinimap - Draws a minimap of the game world.
 * @renderer: The SDL renderer used for rendering.
 *
 * This function draws a minimap representation of the game world on the provided renderer.
 * It uses colors to represent walls and empty spaces based on the `worldMap` data. Additionally,
 * it marks the player's position with a red rectangle and draws a green line indicating the player's
 * direction.
 */
void drawMinimap(SDL_Renderer *renderer)
{
    // Draw the map
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White color
    for (int i = 0; i < MAP_WIDTH; i++)
    {
        for (int j = 0; j < MAP_HEIGHT; j++)
        {
            if (worldMap[i][j] > 0)
            {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Wall color
            }
            else
            {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Empty space color
            }
            SDL_Rect rect = {MINIMAP_POS_X + j * MINIMAP_SCALE, MINIMAP_POS_Y + i * MINIMAP_SCALE, MINIMAP_SCALE, MINIMAP_SCALE};
            SDL_RenderFillRect(renderer, &rect);
        }
    }

    // Draw player position on the map
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Color for player
    SDL_Rect playerRect = {MINIMAP_POS_X + (int)(posX * MINIMAP_SCALE) - 2, MINIMAP_POS_Y + (int)(posY * MINIMAP_SCALE) - 2, 4, 4};
    SDL_RenderFillRect(renderer, &playerRect);

    // Draw the player's direction
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Direction line color
    int dirLineX = (int)(posX * MINIMAP_SCALE + dirX * 5);
    int dirLineY = (int)(posY * MINIMAP_SCALE + dirY * 5);
    SDL_RenderDrawLine(renderer, MINIMAP_POS_X + (int)(posX * MINIMAP_SCALE), MINIMAP_POS_Y + (int)(posY * MINIMAP_SCALE), MINIMAP_POS_X + dirLineX, MINIMAP_POS_Y + dirLineY);
}
