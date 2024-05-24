#include "Balls.h"
#include "windowdata.h"

// Constructor
Balls::Balls(int numBalls, float vel, SDL_Renderer *renderer) : velocityMultiplier(vel), renderer(renderer)
{
    SDL_Color color = {155, 100, 85, 255}; // Red color

    for (int i = 0; i < numBalls; ++i)
    {
        int random_number = rand() % 2 == 0 ? 1 : -1;
        int x = (rand() % WIDTH + 200) - 200;
        int y = (rand() % HEIGHT + 200) - 200;
        float velocityX = (float)(velocityMultiplier * random_number);
        float velocityY = (float)(velocityMultiplier * random_number);
        balls.push_back(new Ball(x, y, 15, velocityX, velocityY, color, renderer));
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

void Balls::setVelocity(float vel)
{
    for (Ball *ball : balls)
    {
        ball->setVelocity((float)(vel * ball->getVelocityX()), (float)(vel * ball->getVelocityY()));
    }
}