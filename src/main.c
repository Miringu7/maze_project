#include "../inc/main.h"

// SDL variables
SDL_Window *gWindow = NULL;
SDL_Renderer *gRenderer = NULL;
TTF_Font *gFont = NULL;

/**
 * main - Entry point for the raycasting SDL application
 * @argc: Argument count
 * @args: Argument vector
 *
 * Description: Initializes the SDL, loads textures, handles the main event
 * loop and renders the game screen. Also, it handles the cleaning up of
 * resources before exiting.
 * Return: 0 on success, 1 on incorrect usage, -1 on initialization failure
 */
int main(int argc, char *args[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <map file>\n", args[0]);
        return 1;
    }

    const char *mapFile = args[1];
    loadMap(mapFile);

    if (!initSDL())
    {
        fprintf(stderr, "Failed to initialize!\n");
        return -1;
    }

    SDL_Surface *textures[8];    // Array to hold textures
    SDL_Surface *groundTexture;  // Ground texture
    SDL_Surface *ceilingTexture; // Ceiling texture
    SDL_Texture *wallTextures[8];
    SDL_Texture *groundTex;
    SDL_Texture *ceilingTex;
    SDL_Texture *weaponTextures[NUM_WEAPONS];

    int isRaining = 0; // State to check if it's raining

    // Load textures
    textures[0] = IMG_Load("./src/textures/texture4.jpeg");
    textures[1] = IMG_Load("./src/textures/texture4.jpeg");
    textures[2] = IMG_Load("./src/textures/texture4.jpeg");
    textures[3] = IMG_Load("./src/textures/texture4.jpeg");
    textures[4] = IMG_Load("./src/textures/texture4.jpeg");
    textures[5] = IMG_Load("./src/textures/texture4.jpeg");
    textures[6] = IMG_Load("./src/textures/texture4.jpeg");
    textures[7] = IMG_Load("./src/textures/texture4.jpeg");

    groundTexture = IMG_Load("./src/textures/ground5.jpg");
    ceilingTexture = IMG_Load("./src/textures/sky.jpg");

    if (!textures[0] || !textures[1] || !textures[2] || !textures[3] || !textures[4] || !textures[5])
    {
        printf("Failed to load textures! SDL_image Error: %s\n", IMG_GetError());
        return -1;
    }

    for (int i = 0; i < 8; ++i)
    {
        wallTextures[i] = SDL_CreateTextureFromSurface(gRenderer, textures[i]);
        SDL_FreeSurface(textures[i]);
    }

    groundTex = SDL_CreateTextureFromSurface(gRenderer, groundTexture);
    SDL_FreeSurface(groundTexture);

    ceilingTex = SDL_CreateTextureFromSurface(gRenderer, ceilingTexture);
    SDL_FreeSurface(ceilingTexture);

    loadWeaponTextures(gRenderer, weaponTextures);

    bool quit = false;
    SDL_Event e;

    double oldTime = 0, time = 0, frameTime;

    while (!quit)
    {
        frameTime = (time - oldTime) / 1000.0;
        oldTime = time;

        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN)
            {
                if (e.key.keysym.sym == SDLK_ESCAPE)
                {
                    quit = true;
                }
                else if (e.key.keysym.sym == SDLK_SPACE)
                {
                    currentWeapon = (currentWeapon + 1) % NUM_WEAPONS;
                }
                else if (e.key.keysym.sym == SDLK_r)
                {
                    isRaining = !isRaining;
                }
                else if (e.key.keysym.sym == SDLK_LEFT)
                {
                    // Rotate left
                    double oldDirX = dirX;
                    dirX = dirX * cos(0.1) - dirY * sin(0.1);
                    dirY = oldDirX * sin(0.1) + dirY * cos(0.1);
                    double oldPlaneX = planeX;
                    planeX = planeX * cos(0.1) - planeY * sin(0.1);
                    planeY = oldPlaneX * sin(0.1) + planeY * cos(0.1);
                }
                else if (e.key.keysym.sym == SDLK_RIGHT)
                {
                    // Rotate right
                    double oldDirX = dirX;
                    dirX = dirX * cos(-0.1) - dirY * sin(-0.1);
                    dirY = oldDirX * sin(-0.1) + dirY * cos(-0.1);
                    double oldPlaneX = planeX;
                    planeX = planeX * cos(-0.1) - planeY * sin(-0.1);
                    planeY = oldPlaneX * sin(-0.1) + planeY * cos(-0.1);
                }
            }
        }

        updateCameraPosition(moveSpeed);
        drawFloorAndCeiling(gRenderer, groundTex, ceilingTex);
        redrawScreen(frameTime, gRenderer, gFont, wallTextures, weaponTextures);
    }

    for (int w = 0; w < NUM_WEAPONS; w++)
    {
        SDL_DestroyTexture(weaponTextures[w]);
    }
    for (int i = 0; i < 8; ++i)
    {
        SDL_DestroyTexture(wallTextures[i]);
    }
    SDL_DestroyTexture(groundTex);
    SDL_DestroyTexture(ceilingTex);
    closeSDL(gWindow, gRenderer, gFont);
    return 0;
}

/**
 * initSDL - Initializes SDL, creates a window and renderer, and loads the font
 *
 * Description: This function initializes the SDL library, creates the window and
 * renderer, and initializes the SDL_ttf library for font rendering. It also loads
 * the specified font to be used in the game.
 * Return: true if initialization was successful, false otherwise
 */
bool initSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    gWindow = SDL_CreateWindow("SDL Raycasting", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == NULL)
    {
        fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == NULL)
    {
        fprintf(stderr, "Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    if (TTF_Init() == -1)
    {
        fprintf(stderr, "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return false;
    }

    gFont = loadFont("/home/miringu/alx/maze_project/src/fonts/ArialRegular.ttf", 28);
    if (gFont == NULL)
    {
        fprintf(stderr, "Failed to load font!\n");
        return false;
    }

    return true;
}