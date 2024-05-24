#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL2/SDL.h>
#include "windowdata.h"
#include "balls.h"

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event event;

Uint32 startFrame, endFrame;
int frameDelay = 1000 / 60;
int runTime;

Balls *balls; // Declare a pointer to a Balls object

void init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);

    balls = new Balls(1000, renderer); // Initialize the Balls object with 10 balls
}

void render()
{
    SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255);
    SDL_RenderClear(renderer);

    balls->render(); // Render all balls

    SDL_RenderPresent(renderer);
}

void update()
{
    balls->update(); // Update all balls
}

int main()
{
    init();

    while (true)
    {
        startFrame = SDL_GetTicks();

        update();
        render();

        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
        {
            break;
        }

        endFrame = SDL_GetTicks();

        runTime = endFrame - startFrame;
        std::cout << runTime << std::endl;
        if (runTime < frameDelay)
        {

            SDL_Delay(frameDelay - runTime);
        }
    }

    delete balls;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
