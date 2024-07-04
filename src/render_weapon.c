#include "../inc/main.h"

/**
 * renderWeapon - Renders the current weapon on the screen
 * @renderer: The SDL_Renderer to draw on
 * @weaponTextures: Array of SDL_Textures for the weapons
 *
 * Description: This function draws the currently selected weapon
 * at the bottom center of the screen. The weapon texture is scaled
 * to fit within a predefined rectangle.
 * Return: void
 */
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
