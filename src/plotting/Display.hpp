#pragma once

// System
#include <memory>
#include <vector>

// External
#include "SDL2/SDL.h"

// User Defined
#include "../utility.hpp"

class Display
{

public:
    Display(/* args */);
    ~Display();

    void setWindow(SDL_Window *win);
    void setRenderer(SDL_Renderer *win);

    SDL_Window *getWindow() const;
    SDL_Renderer *getRenderer() const;
    
    void drawLine(const Point2D& startPos, const Point2D& endPos);
    void drawLines(const std::vector<Point2D>& dataPoint2D);


private:
    int mScreenWidth;
    int mScreenHeight;
    SDL_Window *mWindow;
    SDL_Renderer *mRenderer;
};
