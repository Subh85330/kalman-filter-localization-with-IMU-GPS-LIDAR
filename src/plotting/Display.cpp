#include <iostream>

#include "Display.hpp"

Display::Display() : mScreenWidth(1800), mScreenHeight(980), mIsRunning(1)
{
    mWindow = SDL_CreateWindow("Kalman Filters Sim", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mScreenWidth, mScreenHeight, SDL_WINDOW_SHOWN);
    if (!mWindow)
    {
        std::cout << "Window not created " << SDL_GetError() << std::endl;
    }
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
    SDL_Init(SDL_INIT_VIDEO);
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

void Display::setIsRunning(const bool &isRunning)
{
    mIsRunning = isRunning;
}

void Display::setDrawColor(int r, int g, int b, int alpha)
{
    SDL_SetRenderDrawColor(mRenderer, r, g, b, alpha);
}

SDL_Window *Display::getWindow() const
{
    return mWindow;
}
SDL_Renderer *Display::getRenderer() const
{
    return mRenderer;
}
bool Display::getIsRunning() const
{
    return mIsRunning;
}

void Display::drawLine(const Point2D &startPos, const Point2D &endPos)
{
    SDL_RenderDrawLine(mRenderer, startPos.x, startPos.y, endPos.x, endPos.y);
}

void Display::drawLines(const std::vector<Point2D> &dataPoint2D)
{
    if (dataPoint2D.size() > 1)
    {
        for (int i = 0; i < dataPoint2D.size() - 1; ++i)
        {
            drawLine(dataPoint2D[i], dataPoint2D[i + 1]);
        }
    }
}

void Display::showDisplay()
{
    SDL_RenderPresent(mRenderer);
}

void Display::processInput()
{
    // SDL_Event event;
    // while (SDL_PollEvent(&event) != 0)
    // {
    //     if (event.type == SDL_QUIT)
    //     {
    //         mIsRunning = false;
    //     }
    //     else if (event.type == SDL_KEYDOWN)
    //     {
    //         switch (event.key.keysym.sym)
    //         {
    //         case SDLK_ESCAPE:
    //             mIsRunning = false;
    //             break;
    //         case SDLK_i:

    //         default:
    //             break;
    //         }
    //     }
    // }
}

void Display::resetDisplay()
{
    setDrawColor(100, 100, 100, 100);
    SDL_RenderClear(mRenderer);
}
