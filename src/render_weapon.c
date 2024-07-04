#include "../inc/main.h"

void renderWeapon(SDL_Renderer *renderer, SDL_Texture *weaponTextures[])
{
    int weaponWidth = 128;
    int weaponHeight = 128; // Adjust based on your weapon texture size
    SDL_Rect weaponRect = {
        (SCREEN_WIDTH - weaponWidth) / 2,
        SCREEN_HEIGHT - weaponHeight - 20,
        weaponWidth,
        weaponHeight};

    SDL_RenderCopy(renderer, weaponTextures[currentWeapon], NULL, &weaponRect);
}