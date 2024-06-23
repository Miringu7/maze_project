#ifndef MAIN_H
#define MAIN_H

#include "globals.h"
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// Constants
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MAP_WIDTH 24
#define MAP_HEIGHT 24

// Buffer for rendering
// Uint32 buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
// #define M_PI 3.14159265

// Structures
typedef struct
{
    Uint8 r;
    Uint8 g;
    Uint8 b;
} ColorRGB;

// Add orientations for walls
typedef enum
{
    NORTH_SOUTH,
    EAST_WEST
} WallOrientation;

extern int worldMap[MAP_WIDTH][MAP_HEIGHT];

// Function prototypes
// bool initSDL(SDL_Window *gWindow, SDL_Renderer *gRenderer, TTF_Font *gFont);
bool initSDL();
void closeSDL(SDL_Window *gWindow, SDL_Renderer *gRenderer, TTF_Font *gFont);
void castRays(SDL_Renderer *gRenderer);
void renderTexture(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y);
void drawVerticalLine(int x, int y1, int y2, ColorRGB color, SDL_Renderer *gRenderer, WallOrientation orientation);
void redrawScreen(float frameTime, SDL_Renderer *gRenderer, TTF_Font *gFont);
TTF_Font *loadFont(const char *filePath, int fontSize);
SDL_Surface *renderTextSurface(TTF_Font *font, const char *text, SDL_Color textColor);
SDL_Texture *createTextureFromSurface(SDL_Renderer *renderer, SDL_Surface *surface);
void renderFPS(float frameTime, SDL_Renderer *gRenderer, TTF_Font *gFont);
void updateCameraPosition(double moveSpeed);

#endif
