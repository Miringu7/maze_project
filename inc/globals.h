#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdbool.h>

// Colors
#define COLOR_SKY \
    (ColorRGB) { 135, 206, 235 } // Light blue
#define COLOR_GROUND \
    (ColorRGB) { 139, 69, 19 } // Brown

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

#endif // GLOBALS_H
