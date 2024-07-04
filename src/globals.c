#include "../inc/main.h"

// Define the world map array with dimensions MAP_WIDTH x MAP_HEIGHT
int worldMap[MAP_WIDTH][MAP_HEIGHT];

// Player position variables
double posX = 22, posY = 12; // Initial x and y start position

// Define player direction and camera plane for raycasting
double dirX = -1, dirY = 0;       // Initial direction vector
double planeX = 0, planeY = 0.66; // Camera plane (Field of View)

// Adjust movement speed as necessary
double moveSpeed = 0.5;

// State to check current weapon (initially set to 0)
int currentWeapon = 0;
