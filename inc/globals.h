#ifndef GLOBALS_H
#define GLOBALS_H

#include "main.h"

// Colors
#define COLOR_SKY \
    (ColorRGB) { 135, 206, 235 } // Light blue
#define COLOR_GROUND \
    (ColorRGB) { 139, 69, 19 } // Brown

#define MINIMAP_SCALE 5
#define MINIMAP_WIDTH (MAP_WIDTH * MINIMAP_SCALE)
#define MINIMAP_HEIGHT (MAP_HEIGHT * MINIMAP_SCALE)
#define MINIMAP_POS_X 10
#define MINIMAP_POS_Y 10
#define NUM_WEAPONS 2

// Constants for textures
// #define NUM_TEXTURES 8
// #define texWidth 64
// #define texHeight 64

// Texture array
// Uint32 texture[NUM_TEXTURES][texWidth * texHeight];

extern double posX, posY;
extern double dirX, dirY;
extern double planeX, planeY;
extern double moveSpeed;
extern int currentWeapon;

#endif // GLOBALS_H
