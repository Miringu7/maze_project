#include "../inc/main.h"

/**
 * loadFont - Loads a TTF font from file.
 * @filePath: The path to the font file.
 * @fontSize: The size of the font to load.
 * Return: A pointer to the loaded TTF_Font, or NULL on failure.
 */
TTF_Font *loadFont(const char *filePath, int fontSize)
{
    TTF_Font *font = TTF_OpenFont(filePath, fontSize);
    if (font == NULL)
    {
        fprintf(stderr, "Failed to load font %s! SDL_ttf Error: %s\n", filePath, TTF_GetError());
    }
    return font;
}

/**
 * renderTextSurface - Renders text to an SDL surface.
 * @font: The TTF_Font to use for rendering.
 * @text: The text string to render.
 * @textColor: The color of the rendered text.
 * @Return: A pointer to the rendered SDL_Surface, or NULL on failure.
 */
SDL_Surface *renderTextSurface(TTF_Font *font, const char *text, SDL_Color textColor)
{
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, textColor);
    if (textSurface == NULL)
    {
        fprintf(stderr, "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    }
    return textSurface;
}
