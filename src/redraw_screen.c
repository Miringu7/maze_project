#include "../inc/main.h"

/**
 * redrawScreen - Redraws the game screen
 * @frameTime: Time elapsed per frame
 * @gRenderer: The SDL_Renderer to draw on
 * @gFont: The TTF_Font used for rendering text
 * @wallTextures: Array of SDL_Textures for wall textures
 * @weaponTextures: Array of SDL_Textures for weapon textures
 *
 * Description: This function redraws the entire game screen, including
 * casting rays to render walls, rendering the FPS, drawing the minimap,
 * and rendering the current weapon. It then presents the rendered frame
 * to the screen.
 * Return: void
 */
void redrawScreen(float frameTime, SDL_Renderer *gRenderer, TTF_Font *gFont, SDL_Texture **wallTextures, SDL_Texture *weaponTextures[])
{
    // Cast rays and render walls
    castRays(gRenderer, wallTextures);

    // Render FPS
    renderFPS(frameTime, gRenderer, gFont);

    // Draw minimap
    drawMinimap(gRenderer);

    // Render weapon
    renderWeapon(gRenderer, weaponTextures);

    // Present everything
    SDL_RenderPresent(gRenderer);
}
