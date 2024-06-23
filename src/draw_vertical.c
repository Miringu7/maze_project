#include "../inc/main.h"

void drawVerticalLine(int x, int y1, int y2, ColorRGB color, SDL_Renderer *gRenderer, WallOrientation orientation)
{
    // SDL_SetRenderDrawColor(gRenderer, color.r, color.g, color.b, 255);
    // SDL_RenderDrawLine(gRenderer, x, y1, x, y2);

    // Adjust color based on orientation
    if (orientation == NORTH_SOUTH)
    {
        // Set color for walls facing north-south
        SDL_SetRenderDrawColor(gRenderer, color.r, color.g, color.b, 255);
    }
    else if (orientation == EAST_WEST)
    {
        // Set color for walls facing east-west
        // SDL_SetRenderDrawColor(gRenderer, color.r / 2, color.g / 2, color.b / 2, 255);
        SDL_SetRenderDrawColor(gRenderer, color.r, color.g, color.b, 255);
    }

    SDL_RenderDrawLine(gRenderer, x, y1, x, y2);
}