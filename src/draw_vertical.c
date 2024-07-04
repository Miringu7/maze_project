#include "../inc/main.h"

/**
 * drawVerticalLine - Draws a vertical line on the renderer.
 * @x: The x-coordinate of the vertical line.
 * @y1: The starting y-coordinate of the vertical line.
 * @y2: The ending y-coordinate of the vertical line.
 * @gRenderer: The SDL renderer used for rendering.
 * @orientation: The orientation of the wall (NORTH_SOUTH or EAST_WEST).
 * @color: The RGB color for the vertical line.
 *
 * This function draws a vertical line on the SDL renderer from (x, y1) to (x, y2) with
 * the specified color based on the orientation of the wall. The orientation determines
 * how the color is adjusted for different directions.
 */
void drawVerticalLine(int x, int y1, int y2, SDL_Renderer *gRenderer, WallOrientation orientation, ColorRGB color)
{
    // Adjust color based on orientation
    if (orientation == NORTH_SOUTH)
    {
        // Set color for walls facing north-south
        SDL_SetRenderDrawColor(gRenderer, color.r, color.g, color.b, 255);
    }
    else if (orientation == EAST_WEST)
    {
        // Set color for walls facing east-west
        SDL_SetRenderDrawColor(gRenderer, color.r, color.g, color.b, 255);
    }

    // Draw the vertical line
    SDL_RenderDrawLine(gRenderer, x, y1, x, y2);
}
