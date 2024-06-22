#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// Constants
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define MAP_WIDTH 24
#define MAP_HEIGHT 24

// Structures
typedef struct
{
    Uint8 r;
    Uint8 g;
    Uint8 b;
} ColorRGB;

// Function prototypes
// bool initSDL(SDL_Window *gWindow, SDL_Renderer *gRenderer, TTF_Font *gFont);
bool initSDL();
void closeSDL(SDL_Window *gWindow, SDL_Renderer *gRenderer, TTF_Font *gFont);
void castRays(SDL_Renderer *gRenderer);
void renderTexture(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y);
void drawVerticalLine(int x, int y1, int y2, ColorRGB color, SDL_Renderer *gRenderer);
void redrawScreen(float frameTime, SDL_Renderer *gRenderer, TTF_Font *gFont);
TTF_Font *loadFont(const char *filePath, int fontSize);
SDL_Surface *renderTextSurface(TTF_Font *font, const char *text, SDL_Color textColor);
SDL_Texture *createTextureFromSurface(SDL_Renderer *renderer, SDL_Surface *surface);
void renderText(const char *text, int x, int y, SDL_Color color);
void renderFPS(float frameTime, SDL_Renderer *gRenderer, TTF_Font *gFont);

#endif
