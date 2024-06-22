#include "../inc/main.h"

void drawVerticalLine(int x, int y1, int y2, ColorRGB color, SDL_Renderer *gRenderer)
{
    SDL_SetRenderDrawColor(gRenderer, color.r, color.g, color.b, 255);
    SDL_RenderDrawLine(gRenderer, x, y1, x, y2);
}