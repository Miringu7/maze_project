#include "../inc/main.h"

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
    // int textHeight = textSurface->h;
    int posX = SCREEN_WIDTH - textWidth - 10;
    int posY = 10;

    renderTexture(gRenderer, textTexture, posX, posY);
    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
}