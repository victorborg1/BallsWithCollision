#include "Balls.h"
#include "windowdata.h"

// Constructor
Balls::Balls(int radius, int numBalls, float vel, SDL_Renderer *renderer) : radius(radius), numBalls(numBalls), velocity(vel), renderer(renderer)
{
    SDL_Color color = {155, 100, 85, 255}; // Red color

    for (int i = 0; i < numBalls; ++i)
    {
        addBall(color);
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

void Balls::setRadius(int r)
{
    for (Ball *ball : balls)
    {
        ball->setBallRadius(r);
    }
}

void Balls::setNumBalls(int num)
{
    if (num > numBalls)
    {
        SDL_Color color = {155, 100, 85, 255};
        for (int i = numBalls; i < num; ++i)
        {
            addBall(color);
        }
    }
    else if (num < numBalls)
    {
        for (int i = numBalls; i > num; --i)
        {
            delete balls.back();
            balls.pop_back();
        }
    }
    numBalls = num;
}

void Balls::addBall(SDL_Color color)
{
    int random_number = rand() % 2 == 0 ? 1 : -1;
    int x = (rand() % WIDTH + 200) - 200;
    int y = (rand() % HEIGHT + 200) - 200;
    float velocityX = (float)(velocity * random_number);
    float velocityY = (float)(velocity * random_number);
    balls.push_back(new Ball(x, y, radius, velocityX, velocityY, color, renderer));
}