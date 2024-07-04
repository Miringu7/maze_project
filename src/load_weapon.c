#include "../inc/main.h"

/**
 * loadWeaponTextures - Loads weapon textures from files into an array of SDL_Textures.
 * @renderer: The SDL renderer used for rendering.
 * @weaponTextures[]: Array of SDL_Texture pointers to store loaded textures.
 */
void loadWeaponTextures(SDL_Renderer *renderer, SDL_Texture *weaponTextures[])
{
    // Array of file paths for weapon textures
    const char *weaponFiles[NUM_WEAPONS] = {
        "./src/textures/gun1.jpeg",
        "./src/textures/gun2.jpeg"};

    // Load each weapon texture file into the array
    for (int w = 0; w < NUM_WEAPONS; w++)
    {
        SDL_Surface *surface = IMG_Load(weaponFiles[w]);
        if (!surface)
        {
            fprintf(stderr, "Failed to load weapon texture %s! SDL_image Error: %s\n", weaponFiles[w], IMG_GetError());
            return; // Return on error
        }

        weaponTextures[w] = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }
}
