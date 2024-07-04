#include "../inc/main.h"

void drawFloorAndCeiling(SDL_Renderer *renderer, SDL_Texture *floorTexture, SDL_Texture *ceilingTexture)
{
    for (int y = SCREEN_HEIGHT / 2 + 1; y < SCREEN_HEIGHT; y++)
    {
        double rayDirX0 = dirX - planeX;
        double rayDirY0 = dirY - planeY;
        double rayDirX1 = dirX + planeX;
        double rayDirY1 = dirY + planeY;

        int p = y - SCREEN_HEIGHT / 2;
        double posZ = 0.5 * SCREEN_HEIGHT;
        double rowDistance = posZ / p;

        double floorStepX = rowDistance * (rayDirX1 - rayDirX0) / SCREEN_WIDTH;
        double floorStepY = rowDistance * (rayDirY1 - rayDirY0) / SCREEN_WIDTH;

        double floorX = posX + rowDistance * rayDirX0;
        double floorY = posY + rowDistance * rayDirY0;

        for (int x = 0; x < SCREEN_WIDTH; x++)
        {
            int cellX = (int)(floorX);
            int cellY = (int)(floorY);

            int tx = (int)(64 * (floorX - cellX)) & (64 - 1);
            int ty = (int)(64 * (floorY - cellY)) & (64 - 1);

            floorX += floorStepX;
            floorY += floorStepY;

            SDL_Rect floorSrcRect = {tx, ty, 1, 1};
            SDL_Rect floorDestRect = {x, y, 1, 1};
            SDL_Rect ceilingDestRect = {x, SCREEN_HEIGHT - y - 1, 1, 1};

            SDL_RenderCopy(renderer, floorTexture, &floorSrcRect, &floorDestRect);
            SDL_RenderCopy(renderer, ceilingTexture, &floorSrcRect, &ceilingDestRect);
        }
    }
}