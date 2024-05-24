#pragma once

#include <vector>
#include "Ball.h"

class Balls
{
public:
    Balls(int numBalls, float vel, SDL_Renderer *renderer);
    ~Balls();
    void update();
    void render();
    void setVelocity(float vel);

private:
    int numBalls;
    std::vector<Ball *> balls;
    float velocityMultiplier;
    SDL_Renderer *renderer;
};
