#include "../inc/main.h"

int worldMap[MAP_WIDTH][MAP_HEIGHT];

double posX = 22, posY = 12; // x and y start position
// Define direction and camera plane
double dirX = -1, dirY = 0;       // Initial direction vector
double planeX = 0, planeY = 0.66; // Camera plane (FOV)
double moveSpeed = 0.5;           // Adjust movement speed as necessary

// SDL_Texture *textureWall; // SDL texture for walls
// SDL_Texture *wallTextures[4];
int currentWeapon = 0;
