#pragma once

#include <SDL2/SDL.h>

class Ball
{
public:
    Ball(int x, int y, int radius, float velocityX, float velocityY, SDL_Color color, SDL_Renderer *renderer);
    ~Ball();
    void update();
    void render();
    void setVelocity(float velocityX, float velocityY);
    void setBallRadius(int r);
    float getVelocityX();
    float getVelocityY();

private:
    int x, y;
    int radius;
    float velocityX, velocityY;
    SDL_Color color;
    SDL_Renderer *renderer;
};
