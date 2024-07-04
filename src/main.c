#include "../inc/main.h"

// SDL variables
SDL_Window *gWindow = NULL;
SDL_Renderer *gRenderer = NULL;
TTF_Font *gFont = NULL;

int main(int argc, char *args[])
{
    //(void)argc;
    //(void)args;
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <map file>\n", args[0]);
        return 1;
    }

    const char *mapFile = args[1];
    loadMap(mapFile);

    // if (!initSDL(gWindow, gRenderer, gFont))
    if (!initSDL())
    {
        fprintf(stderr, "Failed to initialize!\n");
        return -1;
    }
    SDL_Surface *textures[8];    // Array to hold textures
    SDL_Surface *groundTexture;  // Ground texture
    SDL_Surface *ceilingTexture; // Ceiling texture
    // SDL_Texture *textureWall; // SDL texture for walls
    SDL_Texture *wallTextures[8];
    SDL_Texture *groundTex;
    SDL_Texture *ceilingTex;
    textures[0] = IMG_Load("./src/textures/texture4.jpeg");
    textures[1] = IMG_Load("./src/textures/texture4.jpeg");
    textures[2] = IMG_Load("./src/textures/texture4.jpeg");
    textures[3] = IMG_Load("./src/textures/texture4.jpeg");
    textures[4] = IMG_Load("./src/textures/texture4.jpeg");
    textures[5] = IMG_Load("./src/textures/texture4.jpeg");
    textures[6] = IMG_Load("./src/textures/texture4.jpeg");
    textures[7] = IMG_Load("./src/textures/texture4.jpeg");

    groundTexture = IMG_Load("./src/textures/ground2.jpg");
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
        //  Free the surface after creating the texture
    }

    groundTex = SDL_CreateTextureFromSurface(gRenderer, groundTexture);
    SDL_FreeSurface(groundTexture); // free the surface after creation

    ceilingTex = SDL_CreateTextureFromSurface(gRenderer, ceilingTexture);
    SDL_FreeSurface(ceilingTexture); // free the surface after creation

    // SDL_EnableKeyRepeat(0, 0);

    // rotateCamera(3.142 / 4);

    bool quit = false;
    SDL_Event e;

    // Uint32 startTicks, frameTicks;
    double oldTime = 0, time = 0, frameTime;
    // int fps = 0;

    while (!quit)
    {
        // startTicks = SDL_GetTicks();
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
                // Handle rotation here (Task 2)
                if (e.key.keysym.sym == SDLK_LEFT)
                {
                    // rotate left
                    double oldDirX = dirX;
                    dirX = dirX * cos(0.1) - dirY * sin(0.1);
                    dirY = oldDirX * sin(0.1) + dirY * cos(0.1);
                    double oldPlaneX = planeX;
                    planeX = planeX * cos(0.1) - planeY * sin(0.1);
                    planeY = oldPlaneX * sin(0.1) + planeY * cos(0.1);
                }
                else if (e.key.keysym.sym == SDLK_RIGHT)
                {
                    // rotate right
                    double oldDirX = dirX;
                    dirX = dirX * cos(-0.1) - dirY * sin(-0.1);
                    dirY = oldDirX * sin(-0.1) + dirY * cos(-0.1);
                    double oldPlaneX = planeX;
                    planeX = planeX * cos(-0.1) - planeY * sin(-0.1);
                    planeY = oldPlaneX * sin(-0.1) + planeY * cos(-0.1);
                }
            }
        }

        // redrawScreen(fps, gRenderer, gFont);
        updateCameraPosition(moveSpeed);
        drawFloorAndCeiling(gRenderer, groundTex, ceilingTex);
        redrawScreen(frameTime, gRenderer, gFont, wallTextures);

        // if (frameTicks < 1000 / 60)
        //{
        // SDL_Delay(1000 / 60 - frameTicks);
        //}

        // fps = 1 / frameTicks;
    }

    for (int i = 0; i < 4; ++i)
    {
        SDL_DestroyTexture(wallTextures[i]);
    }
    SDL_DestroyTexture(groundTex);
    SDL_DestroyTexture(ceilingTex);
    closeSDL(gWindow, gRenderer, gFont);
    return 0;
}

// bool initSDL(SDL_Window *gWindow, SDL_Renderer *gRenderer, TTF_Font *gFont)
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