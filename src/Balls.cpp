#include "Balls.h"
#include "windowdata.h"

// Constructor
Balls::Balls(int numBalls, SDL_Renderer *renderer) : renderer(renderer)
{
    SDL_Color color = {255, 100, 0, 255}; // Red color
    for (int i = 0; i < numBalls; ++i)
    {
        int x = WIDTH / 2;
        int y = HEIGHT / 2;
        int velocityX = (rand() % 50) - 10; // -5 to 5
        int velocityY = (rand() % 50) - 10; // -5 to 5
        balls.push_back(new Ball(x, y, 2, velocityX, velocityY, color, renderer));
    }
}

// Destructor
Balls::~Balls()
{
    for (Ball *ball : balls)
    {
        delete ball;
    }
}

void Balls::update()
{
    for (Ball *ball : balls)
    {
        ball->update();
    }
}

void Balls::render()
{
    for (Ball *ball : balls)
    {
        ball->render();
    }
}