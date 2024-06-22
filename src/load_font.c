#include "../inc/main.h"

TTF_Font *loadFont(const char *filePath, int fontSize)
{
    TTF_Font *font = TTF_OpenFont(filePath, fontSize);
    if (font == NULL)
    {
        fprintf(stderr, "Failed to load font %s! SDL_ttf Error: %s\n", filePath, TTF_GetError());
    }
    return font;
}

SDL_Surface *renderTextSurface(TTF_Font *font, const char *text, SDL_Color textColor)
{
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, textColor);
    if (textSurface == NULL)
    {
        fprintf(stderr, "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    }
    return textSurface;
}