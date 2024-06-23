#include "../inc/main.h"

void updateCameraPosition(double moveSpeed)
{
    // Handle movement based on keys pressed
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    // Move forward/backward along the direction vector dirX, dirY
    if (keystates[SDL_SCANCODE_W])
    {
        if (worldMap[(int)(posX + dirX * moveSpeed)][(int)posY] == 0)
            posX += dirX * moveSpeed;
        if (worldMap[(int)posX][(int)(posY + dirY * moveSpeed)] == 0)
            posY += dirY * moveSpeed;
    }
    if (keystates[SDL_SCANCODE_S])
    {
        if (worldMap[(int)(posX - dirX * moveSpeed)][(int)posY] == 0)
            posX -= dirX * moveSpeed;
        if (worldMap[(int)posX][(int)(posY - dirY * moveSpeed)] == 0)
            posY -= dirY * moveSpeed;
    }
    // Move left/right perpendicular to the direction vector
    if (keystates[SDL_SCANCODE_A])
    {
        if (worldMap[(int)(posX - planeX * moveSpeed)][(int)posY] == 0)
            posX -= planeX * moveSpeed;
        if (worldMap[(int)posX][(int)(posY - planeY * moveSpeed)] == 0)
            posY -= planeY * moveSpeed;
    }
    if (keystates[SDL_SCANCODE_D])
    {
        if (worldMap[(int)(posX + planeX * moveSpeed)][(int)posY] == 0)
            posX += planeX * moveSpeed;
        if (worldMap[(int)posX][(int)(posY + planeY * moveSpeed)] == 0)
            posY += planeY * moveSpeed;
    }
}