#include "../inc/main.h"

void updateCameraPosition(double moveSpeed)
{
    // Handle movement based on keys pressed
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    // Move forward/backward along the direction vector dirX, dirY
    if (keystates[SDL_SCANCODE_W])
    {
        double nextX = posX + dirX * moveSpeed;
        double nextY = posY + dirY * moveSpeed;
        if (worldMap[(int)nextX][(int)posY] == 0)
            posX = nextX;
        if (worldMap[(int)posX][(int)nextY] == 0)
            posY = nextY;
    }
    if (keystates[SDL_SCANCODE_S])
    {
        double nextX = posX - dirX * moveSpeed;
        double nextY = posY - dirY * moveSpeed;
        if (worldMap[(int)nextX][(int)posY] == 0)
            posX = nextX;
        if (worldMap[(int)posX][(int)nextY] == 0)
            posY = nextY;
    }
    // Move left/right perpendicular to the direction vector
    if (keystates[SDL_SCANCODE_A])
    {
        double nextX = posX - planeX * moveSpeed;
        double nextY = posY - planeY * moveSpeed;
        if (worldMap[(int)nextX][(int)posY] == 0)
            posX = nextX;
        if (worldMap[(int)posX][(int)nextY] == 0)
            posY = nextY;
    }
    if (keystates[SDL_SCANCODE_D])
    {
        double nextX = posX + planeX * moveSpeed;
        double nextY = posY + planeY * moveSpeed;
        if (worldMap[(int)nextX][(int)posY] == 0)
            posX = nextX;
        if (worldMap[(int)posX][(int)nextY] == 0)
            posY = nextY;
    }
}