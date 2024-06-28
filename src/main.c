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
        redrawScreen(frameTime, gRenderer, gFont);

        // if (frameTicks < 1000 / 60)
        //{
        // SDL_Delay(1000 / 60 - frameTicks);
        //}

        // fps = 1 / frameTicks;
    }

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