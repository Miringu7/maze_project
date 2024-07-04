#include "../inc/main.h"

/**
 * createTextureFromSurface - Creates an SDL texture from an SDL surface.
 * @renderer: The SDL renderer to create the texture with.
 * @surface: The SDL surface to create the texture from.
 *
 * This function creates an SDL texture from the provided SDL surface using
 * the given renderer. If successful, it returns the created texture; otherwise,
 * it prints an error message to stderr and frees the surface before returning NULL.
 *
 * Returns: A pointer to the created SDL texture, or NULL on failure.
 */
SDL_Texture *createTextureFromSurface(SDL_Renderer *renderer, SDL_Surface *surface)
{
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL)
    {
        fprintf(stderr, "Unable to create texture from surface! SDL Error: %s\n", SDL_GetError());
        SDL_FreeSurface(surface);
        return NULL;
    }
    return texture;
}

/**
 * renderTexture - Renders an SDL texture at the specified coordinates.
 * @renderer: The SDL renderer to render with.
 * @texture: The SDL texture to render.
 * @x: The x-coordinate to render the texture.
 * @y: The y-coordinate to render the texture.
 *
 * This function renders the provided SDL texture onto the renderer at the
 * specified (x, y) coordinates. The size of the rendered texture is automatically
 * determined from the texture itself.
 */
void renderTexture(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y)
{
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
    SDL_RenderCopy(renderer, texture, NULL, &dst);
}
