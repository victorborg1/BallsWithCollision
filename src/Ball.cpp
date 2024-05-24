#include "ball.h"
#include "windowdata.h"

// Constructor
Ball::Ball(int x, int y, int radius, float velocityX, float velocityY, SDL_Color color, SDL_Renderer *renderer)
    : x(x), y(y), radius(radius), velocityX(velocityX), velocityY(velocityY), color(color), renderer(renderer) {}

// Destructor
Ball::~Ball() {}

void Ball::update()
{
    x += velocityX;
    y += velocityY;

    // Check collision with screen boundaries
    if (x - radius < 0)
    {
        x = radius;
        velocityX = -velocityX; // Reverse velocity
    }
    else if (x + radius > WIDTH)
    {
        x = WIDTH - radius;
        velocityX = -velocityX; // Reverse velocity
    }

    if (y - radius < 0)
    {
        y = radius;
        velocityY = -velocityY; // Reverse velocity
    }
    else if (y + radius > HEIGHT)
    {
        y = HEIGHT - radius;
        velocityY = -velocityY; // Reverse velocity
    }
}

void Ball::render()
{
    // Set the color for the ball
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    // Draw the ball as a filled circle
    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w; // Horizontal offset
            int dy = radius - h; // Vertical offset
            if ((dx * dx + dy * dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }
}

void Ball::setVelocity(float velX, float velY)
{
    velocityX = velX;
    velocityY = velY;
}

float Ball::getVelocityX()
{
    if (velocityX > 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

float Ball::getVelocityY()
{
    if (velocityY > 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
