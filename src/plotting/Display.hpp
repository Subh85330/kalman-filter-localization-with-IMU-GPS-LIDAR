#pragma once

// System
#include <memory>
#include <vector>
#include <string>
// External
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

// User Defined
#include "../utility.hpp"

class Display
{

public:
    Display(/* args */);
    ~Display();

    void setWindow(SDL_Window *win);
    void setRenderer(SDL_Renderer *win);
    void setIsRunning(const bool &isRunning);
    void setDrawColor(int r, int g, int b, int alpha);

    SDL_Window *getWindow() const;
    SDL_Renderer *getRenderer() const;
    bool getIsRunning() const;
    double getScreenAspectRation() const;

    void drawLine(const Point2D &startPos, const Point2D &endPos);
    void drawLines(const std::vector<Point2D> &dataPoint2D);
    void drawLines(const std::vector<std::vector<Point2D>> &dataPoint2D);
    void drawText(const std::string text, const Point2D ps, const double scale=1, const SDL_Color color={255,255,255}, bool isCentered=false);
    Point2D transformPoint(Point2D point);

    void setView(double width, double height, double xOffSet, double yOffset);

    void showDisplay();
    void processInput();

    void resetDisplay();

    void generateGrid();
    void renderGrid(int x, int y);

private:
    double mScreenWidth;
    double mScreenHeight;

    double mViewWidth;
    double mViewHeight;
    double mViewXOffset;
    double mViewYOffset;

    SDL_Window *mWindow;
    SDL_Renderer *mRenderer;
    TTF_Font *mFontMain;
    SDL_Texture *gridTexture;
    
    bool mIsRunning;
};
