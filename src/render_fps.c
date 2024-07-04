#include "../inc/main.h"

/**
 * renderFPS - Renders the frames per second (FPS) on the screen
 * @frameTime: Time elapsed per frame
 * @gRenderer: The SDL_Renderer to draw on
 * @gFont: The TTF_Font used for rendering text
 *
 * Description: This function calculates the frames per second (FPS)
 * based on the elapsed frame time and renders it on the screen using
 * the provided SDL renderer and font. The FPS text is displayed in the
 * top-right corner of the screen.
 * Return: void
 */
void renderFPS(float frameTime, SDL_Renderer *gRenderer, TTF_Font *gFont)
{
    char fpsText[32];
    snprintf(fpsText, sizeof(fpsText), "frameTime: %.2f", 1.0 / frameTime);

    SDL_Color textColor = {255, 255, 255, 255};
    SDL_Surface *textSurface = renderTextSurface(gFont, fpsText, textColor);
    if (textSurface == NULL)
    {
        fprintf(stderr, "Failed to render text surface!\n");
        return;
    }
    SDL_Texture *textTexture = createTextureFromSurface(gRenderer, textSurface);
    if (textTexture == NULL)
    {
        SDL_FreeSurface(textSurface);
        fprintf(stderr, "Failed to create texture from surface!\n");
        return;
    }

    int textWidth = textSurface->w;
    int posX = SCREEN_WIDTH - textWidth - 10;
    int posY = 10;

    renderTexture(gRenderer, textTexture, posX, posY);
    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
}
