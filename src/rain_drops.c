#include "../inc/main.h"

/**
 * initializeRaindrops - Initializes the raindrops
 *
 * Description: This function initializes the position and speed of each raindrop.
 * The x and y positions are set randomly within the screen dimensions. The speed
 * of each raindrop is set to a random value between 2 and 4.
 * Return: void
 */
void initializeRaindrops()
{
    for (int i = 0; i < NUM_RAINDROPS; i++)
    {
        raindrops[i].x = rand() % SCREEN_WIDTH;
        raindrops[i].y = rand() % SCREEN_HEIGHT;
        raindrops[i].speed = 2 + rand() % 3;
    }
}

/**
 * updateRaindrops - Updates the position of the raindrops
 *
 * Description: This function updates the position of each raindrop by incrementing
 * the y position by the speed of the raindrop. If a raindrop goes off the screen,
 * it is reset to the top of the screen with a new random x position.
 * Return: void
 */
void updateRaindrops()
{
    for (int i = 0; i < NUM_RAINDROPS; i++)
    {
        raindrops[i].y += raindrops[i].speed;
        if (raindrops[i].y > SCREEN_HEIGHT)
        {
            raindrops[i].x = rand() % SCREEN_WIDTH;
            raindrops[i].y = 0;
        }
    }
}

/**
 * renderRaindrops - Renders the raindrops on the screen
 * @renderer: The SDL_Renderer to draw on
 *
 * Description: This function renders each raindrop as a blue point on the screen.
 * The renderer's draw color is set to blue before drawing the points.
 * Return: void
 */
void renderRaindrops(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Set color to blue for raindrops
    for (int i = 0; i < NUM_RAINDROPS; i++)
    {
        SDL_RenderDrawPoint(renderer, raindrops[i].x, raindrops[i].y);
    }
}
