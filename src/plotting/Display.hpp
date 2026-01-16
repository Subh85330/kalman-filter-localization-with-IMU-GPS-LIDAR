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
    void setIsRunning(const bool& isRunning);
    void setDrawColor(int r, int g, int b, int alpha);


    SDL_Window *getWindow() const;
    SDL_Renderer *getRenderer() const;
    bool getIsRunning() const;
    
    void drawLine(const Point2D& startPos, const Point2D& endPos);
    void drawLines(const std::vector<Point2D>& dataPoint2D);
    void showDisplay();
    void processInput();

    void resetDisplay();

    

private:
    int mScreenWidth;
    int mScreenHeight;
    SDL_Window *mWindow;
    SDL_Renderer *mRenderer;
    bool mIsRunning;
};
