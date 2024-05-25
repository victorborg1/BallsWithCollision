#pragma once

#include <SDL2/SDL.h>

class Slider
{
public:
    Slider(int x, int y, int width, int height, int maxValue, float initialValue, SDL_Renderer *renderer);
    ~Slider();
    void render();
    void handleEvents(SDL_Event event);
    float getSliderValue();

private:
    int x, y, width, height, maxValue;
    float sliderValue;
    bool isDragging;
    SDL_Renderer *renderer;
};