#include "../inc/main.h"

void loadWeaponTextures(SDL_Renderer *renderer, SDL_Texture *weaponTextures[])
{
    const char *weaponFiles[NUM_WEAPONS] = {
        "./src/textures/gun1.jpeg",
        "./src/textures/gun2.jpeg"};

    for (int w = 0; w < NUM_WEAPONS; w++)
    {
        SDL_Surface *surface = IMG_Load(weaponFiles[w]);
        if (!surface)
        {
            printf("Failed to load weapon texture %s! SDL_image Error: %s\n", weaponFiles[w], IMG_GetError());
            return;
        }
        weaponTextures[w] = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }
}