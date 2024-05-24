#pragma once

#include <SDL2/SDL.h>

class Ball
{
public:
    Ball(int x, int y, int radius, int velocityX, int velocityY, SDL_Color color, SDL_Renderer *renderer);
    ~Ball();
    void update();
    void render();

private:
    int x, y;
    int radius;
    int velocityX, velocityY;
    SDL_Color color;
    SDL_Renderer *renderer;
};