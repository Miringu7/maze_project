#ifndef GLOBALS_H
#define GLOBALS_H

#include "main.h"

/**
 * File: globals.h
 * Description: This file contains global variables and definitions used across the SDL raycasting game project.
 * Author: Your Name
 * Date: 2024-07-04
 */

// Colors definitions
#define COLOR_SKY \
    (ColorRGB) { 135, 206, 235 } // Light blue color for the sky
#define COLOR_GROUND \
    (ColorRGB) { 139, 69, 19 } // Brown color for the ground

// Minimap configurations
#define MINIMAP_SCALE 5
#define MINIMAP_WIDTH (MAP_WIDTH * MINIMAP_SCALE)
#define MINIMAP_HEIGHT (MAP_HEIGHT * MINIMAP_SCALE)
#define MINIMAP_POS_X 10
#define MINIMAP_POS_Y 10

// Game constants
#define NUM_WEAPONS 2
#define NUM_RAINDROPS 1000

// Player's position and direction
extern double posX, posY;     // Player's position coordinates
extern double dirX, dirY;     // Player's direction vector
extern double planeX, planeY; // Camera plane for the player's field of view

// Player's movement speed
extern double moveSpeed;

// Current weapon index
extern int currentWeapon;

// Rain effect flag
extern int isRaining;

#endif // GLOBALS_H
