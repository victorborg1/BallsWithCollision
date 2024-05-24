#pragma once

#include <vector>
#include "Ball.h"

class Balls
{
public:
    Balls(int numBalls, SDL_Renderer *renderer);
    ~Balls();
    void update();
    void render();

private:
    std::vector<Ball *> balls;
    SDL_Renderer *renderer;
};
