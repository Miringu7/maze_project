#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdbool.h>

// Colors
#define COLOR_SKY \
    (ColorRGB) { 135, 206, 235 } // Light blue
#define COLOR_GROUND \
    (ColorRGB) { 139, 69, 19 } // Brown

extern double posX, posY;
extern double dirX, dirY;
extern double planeX, planeY;

#endif // GLOBALS_H
