#ifndef MAIN_H
#define MAIN_H

#include "globals.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

/**
 * File: main.h
 * Description: Header file containing constant definitions, structure declarations,
 *              and function prototypes for the SDL raycasting game project.
 * Author: Your Name
 * Date: 2024-07-04
 */

// Constants
#define SCREEN_WIDTH 640  // Width of the game window
#define SCREEN_HEIGHT 480 // Height of the game window
#define MAP_WIDTH 24      // Width of the game map
#define MAP_HEIGHT 24     // Height of the game map

// Structures
typedef struct
{
    Uint8 r; // Red component of the RGB color
    Uint8 g; // Green component of the RGB color
    Uint8 b; // Blue component of the RGB color
} ColorRGB;

typedef enum
{
    NORTH_SOUTH, // Orientation for walls aligned north-south
    EAST_WEST    // Orientation for walls aligned east-west
} WallOrientation;

typedef struct
{
    float x, y;  // Position of the raindrop
    float speed; // Speed of the raindrop
} Raindrop;

// Global variables
extern int worldMap[MAP_WIDTH][MAP_HEIGHT]; // Game world map
extern Raindrop raindrops[NUM_RAINDROPS];   // Array of raindrop structures

// Function prototypes
bool initSDL();
void closeSDL(SDL_Window *gWindow, SDL_Renderer *gRenderer, TTF_Font *gFont);
void castRays(SDL_Renderer *gRenderer, SDL_Texture **wallTextures);
void renderTexture(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y);
void drawVerticalLine(int x, int y1, int y2, SDL_Renderer *gRenderer, WallOrientation orientation, ColorRGB color);
void redrawScreen(float frameTime, SDL_Renderer *gRenderer, TTF_Font *gFont, SDL_Texture **wallTextures, SDL_Texture *weaponTextures[]);
TTF_Font *loadFont(const char *filePath, int fontSize);
SDL_Surface *renderTextSurface(TTF_Font *font, const char *text, SDL_Color textColor);
SDL_Texture *createTextureFromSurface(SDL_Renderer *renderer, SDL_Surface *surface);
void renderFPS(float frameTime, SDL_Renderer *gRenderer, TTF_Font *gFont);
void updateCameraPosition(double moveSpeed);
void loadMap(const char *filename);
void drawMinimap(SDL_Renderer *renderer);
void drawFloorAndCeiling(SDL_Renderer *renderer, SDL_Texture *floorTexture, SDL_Texture *ceilingTexture);
void loadWeaponTextures(SDL_Renderer *renderer, SDL_Texture *weaponTextures[]);
void renderWeapon(SDL_Renderer *renderer, SDL_Texture *weaponTextures[]);
void initializeRaindrops();
void updateRaindrops();
void renderRaindrops(SDL_Renderer *renderer);

#endif // MAIN_H
