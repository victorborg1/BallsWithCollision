#include "ball.h"
#include "windowdata.h"

// Constructor
Ball::Ball(int x, int y, int radius, int velocityX, int velocityY, SDL_Color color, SDL_Renderer *renderer)
    : x(x), y(y), radius(radius), velocityX(velocityX), velocityY(velocityY), color(color), renderer(renderer) {}

// Destructor
Ball::~Ball() {}

void Ball::update()
{
    x += velocityX;
    y += velocityY;

    if (x - radius < 0 || x + radius > WIDTH)
    {
        velocityX = -velocityX;
    }
    if (y - radius < 0 || y + radius > HEIGHT)
    {
        velocityY = -velocityY;
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