#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL2/SDL.h>
#include "windowdata.h"
#include "balls.h"

// Slider parameters
const int SLIDER_X = 50;
const int SLIDER_Y = 50;
const int SLIDER_WIDTH = 300;
const int SLIDER_HEIGHT = 50;

bool dragging = false;
float sliderValue = 1.0f; // Initial slider value (normalized)

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

    balls = new Balls(20, sliderValue, renderer); // Initialize the Balls object with 10 balls
}

// Handle mouse events
void handleEvents(SDL_Event event)
{
    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        if (mouseX >= SLIDER_X && mouseX <= SLIDER_X + SLIDER_WIDTH &&
            mouseY >= SLIDER_Y && mouseY <= SLIDER_Y + SLIDER_HEIGHT)
        {
            dragging = true;
        }
    }
    else if (event.type == SDL_MOUSEBUTTONUP)
    {
        dragging = false;
    }
    else if (event.type == SDL_MOUSEMOTION && dragging)
    {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        // Map mouse position to slider range [1, 10]
        sliderValue = (float)(mouseX - SLIDER_X) / SLIDER_WIDTH * 9 + 1;
        // Clamp slider value to [1, 10]
        if (sliderValue < 1)
            sliderValue = 1;
        if (sliderValue > 10)
            sliderValue = 10;
        balls->setVelocity(sliderValue);
    }
}

void render()
{
    SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255);
    SDL_RenderClear(renderer);

    // Draw slider bar
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect sliderBar = {SLIDER_X, SLIDER_Y + SLIDER_HEIGHT / 2 - 1, SLIDER_WIDTH, 2};
    SDL_RenderFillRect(renderer, &sliderBar);

    // Calculate slider handle size based on slider width
    int handleWidth = SLIDER_WIDTH / 10; // Slider divided into 10 parts

    // Draw slider handle
    SDL_SetRenderDrawColor(renderer, 255, 100, 100, 255);
    SDL_Rect sliderHandle = {
        SLIDER_X + (int)(sliderValue / 11 * SLIDER_WIDTH) - handleWidth / 2, // Adjusted position
        SLIDER_Y - handleWidth / 2,                                          // Center vertically
        handleWidth,                                                         // Adjusted width
        SLIDER_HEIGHT + handleWidth                                          // Adjusted height
    };
    SDL_RenderFillRect(renderer, &sliderHandle);

    balls->render();

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
        handleEvents(event);

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
