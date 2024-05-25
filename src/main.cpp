#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL2/SDL.h>
#include "windowdata.h"
#include "balls.h"
#include "slider.h"

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event event;

Uint32 startFrame, endFrame;
int frameDelay = 1000 / 144;
int runTime;

Balls *balls;
Slider *sliderOne;
Slider *sliderTwo;
Slider *sliderThree;

void init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    sliderOne = new Slider(50, 50, 300, 40, 10, 1.0f, renderer);
    sliderTwo = new Slider(50, 100, 300, 40, 50, 5.0f, renderer);
    sliderThree = new Slider(50, 150, 300, 40, 20, 10.0f, renderer);
    balls = new Balls((int)sliderThree->getSliderValue(), (int)sliderTwo->getSliderValue(), sliderOne->getSliderValue(), renderer);
}

void render()
{
    SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255);
    SDL_RenderClear(renderer);

    sliderOne->render();
    sliderTwo->render();
    sliderThree->render();
    balls->render();

    SDL_RenderPresent(renderer);
}

void update()
{
    balls->update();
}

int main()
{
    init();

    while (true)
    {
        startFrame = SDL_GetTicks();

        update();
        render();
        sliderOne->handleEvents(event);
        sliderTwo->handleEvents(event);
        sliderThree->handleEvents(event);
        balls->setVelocity(sliderOne->getSliderValue());
        balls->setNumBalls((int)sliderTwo->getSliderValue());
        balls->setRadius(sliderThree->getSliderValue());

        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
        {
            break;
        }

        endFrame = SDL_GetTicks();

        runTime = endFrame - startFrame;
        // std::cout << runTime << std::endl;
        if (runTime < frameDelay)
        {

            SDL_Delay(frameDelay - runTime);
        }
    }

    delete balls;
    delete sliderOne;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
