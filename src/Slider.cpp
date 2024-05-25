#include "slider.h"
#include "windowdata.h"

Slider::Slider(int x, int y, int width, int height, int maxValue, float initialValue, SDL_Renderer *renderer) : x(x), y(y), width(width), height(height), maxValue(maxValue), sliderValue(initialValue), isDragging(false), renderer(renderer)
{
}

Slider::~Slider()
{
}

void Slider::handleEvents(SDL_Event event)
{
    int handleWidth = width / 30;
    int handleX = x + (int)((sliderValue - 1) / (maxValue - 1) * width) - handleWidth / 2;

    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        if (mouseX >= handleX && mouseX <= handleX + handleWidth &&
            mouseY >= y - height / 2 && mouseY <= y + height / 2)
        {
            isDragging = true;
        }
    }
    else if (event.type == SDL_MOUSEBUTTONUP)
    {
        isDragging = false;
    }
    else if (event.type == SDL_MOUSEMOTION && isDragging)
    {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        // Map mouse position to slider range [1, 10]
        sliderValue = (float)(mouseX - x) / width * (maxValue - 1) + 1;
        // Clamp slider value to [1, 10]
        if (sliderValue < 1)
            sliderValue = 1;
        if (sliderValue > maxValue)
            sliderValue = maxValue;
    }
}

void Slider::render()
{
    // slider bar
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect sliderBar = {x, y, width, 2};
    SDL_RenderFillRect(renderer, &sliderBar);

    // Calculate slider handle size based on slider width
    int handleWidth = width / 30;
    int handleX = x + (int)((sliderValue - 1) / (maxValue - 1) * width) - handleWidth / 2;
    // slider handle
    SDL_SetRenderDrawColor(renderer, 255, 100, 100, 255);
    SDL_Rect sliderHandle = {
        handleX,
        y - height / 2,
        handleWidth,
        height};
    SDL_RenderFillRect(renderer, &sliderHandle);
}

float Slider::getSliderValue()
{
    return sliderValue;
}