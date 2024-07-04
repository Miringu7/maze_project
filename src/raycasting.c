#include "../inc/main.h"

/**
 * castRays - Casts rays and renders walls using raycasting
 * @gRenderer: The SDL_Renderer to draw on
 * @wallTextures: Array of SDL_Textures for wall textures
 *
 * Description: This function casts rays from the player's position to detect walls,
 * calculates the distance to the walls, and renders the walls on the screen using
 * vertical lines. It uses raycasting to determine the distance and texture of the walls.
 * Return: void
 */
void castRays(SDL_Renderer *gRenderer, SDL_Texture **wallTextures)
{
    for (int x = 0; x < SCREEN_WIDTH; x++)
    {
        double cameraX = 2 * x / (double)SCREEN_WIDTH - 1; // x-coordinate in camera space
        double rayDirX = dirX + planeX * cameraX;
        double rayDirY = dirY + planeY * cameraX;

        int mapX = (int)posX;
        int mapY = (int)posY;

        double sideDistX;
        double sideDistY;

        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
        double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
        double perpWallDist;

        int stepX;
        int stepY;

        int hit = 0;
        int side;

        if (rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (posX - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - posX) * deltaDistX;
        }
        if (rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (posY - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - posY) * deltaDistY;
        }

        while (hit == 0)
        {
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if (worldMap[mapX][mapY] > 0)
                hit = 1;
        }

        if (side == 0)
            perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
        else
            perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

        int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

        int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
        if (drawStart < 0)
            drawStart = 0;
        int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
        if (drawEnd >= SCREEN_HEIGHT)
            drawEnd = SCREEN_HEIGHT - 1;

        ColorRGB color;
        switch (worldMap[mapX][mapY])
        {
        case 1:
            color = (ColorRGB){255, 255, 255};
            break;
        case 2:
            color = (ColorRGB){255, 255, 255};
            break;
        case 3:
            color = (ColorRGB){255, 255, 255};
            break;
        case 4:
            color = (ColorRGB){255, 255, 255};
            break;
        default:
            color = (ColorRGB){255, 255, 255};
            break;
        }

        if (side == 1)
        {
            color.r /= 2;
            color.g /= 2;
            color.b /= 2;
        }

        WallOrientation orientation;
        if (side == 0)
            orientation = EAST_WEST; // Facing east-west
        else
            orientation = NORTH_SOUTH; // Facing north-south

        drawVerticalLine(x, drawStart, drawEnd, gRenderer, orientation, color);
        SDL_Rect wallRect = {x, drawStart, 1, drawEnd - drawStart};
        SDL_RenderCopy(gRenderer, wallTextures[worldMap[mapX][mapY] - 1], NULL, &wallRect);
    }
}
