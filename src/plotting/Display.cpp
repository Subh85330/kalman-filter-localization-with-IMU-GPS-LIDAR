#include "Display.hpp"
#include <iostream>

Display::Display(/* args */): mScreenWidth(1800), mScreenHeight(980)
{
    mWindow = SDL_CreateWindow("Kalman Filters Sim", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mScreenWidth, mScreenHeight, SDL_WINDOW_SHOWN);
    if (!mWindow)
    {
        std::cout << "Window not created " << SDL_GetError() << std::endl;
    }
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);

}

Display::~Display()
{
        SDL_DestroyRenderer(mRenderer);
        SDL_DestroyWindow(mWindow);
        SDL_Quit();
}

void Display::setWindow(SDL_Window *win)
{
    mWindow = win;
}
void Display::setRenderer(SDL_Renderer *renderer)
{
    mRenderer = renderer;
}

SDL_Window *Display::getWindow() const
{
    return mWindow;
}
SDL_Renderer *Display::getRenderer() const
{
    return mRenderer;
}

void Display::drawLine(const Point2D& startPos, const Point2D& endPos)
{
    SDL_RenderDrawLine(mRenderer,startPos.x,startPos.y, endPos.x, endPos.y);
}