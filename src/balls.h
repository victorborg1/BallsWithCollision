#pragma once

#include <vector>
#include "Ball.h"

class Balls
{
public:
    Balls(int radius, int numBalls, float vel, SDL_Renderer *renderer);
    ~Balls();
    void update();
    void render();
    void setVelocity(float vel);
    void setNumBalls(int num);
    void setRadius(int r);
    void addBall(SDL_Color color);

private:
    int radius, numBalls;
    std::vector<Ball *> balls;
    float velocity;
    SDL_Renderer *renderer;
};
