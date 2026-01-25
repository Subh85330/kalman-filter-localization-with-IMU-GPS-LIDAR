#include <iostream>

#include "Display.hpp"

Display::Display() : mScreenWidth(1060), mScreenHeight(980), mIsRunning(1), mViewHeight(mScreenHeight), mViewWidth(mScreenWidth), mViewXOffset(0.0), mViewYOffset(0.0)
{
    mWindow = SDL_CreateWindow("Kalman Filters Sim", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mScreenWidth, mScreenHeight, SDL_WINDOW_SHOWN);
    if (!mWindow)
    {
        std::cout << "Window not created " << SDL_GetError() << std::endl;
    }
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
    
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    mFontMain = TTF_OpenFont("Roboto-Regular.ttf",20);
    if(!mFontMain)
    {
        std::cout<<"mFontMain Not Available "<<TTF_GetError()<<std::endl;
    }
    generateGrid();
}

Display::~Display()
{
    TTF_CloseFont(mFontMain);
    SDL_DestroyTexture(gridTexture);
    gridTexture = NULL;
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    TTF_Quit();
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
double Display::getScreenAspectRation() const
{
    return mScreenWidth / mScreenHeight;
}

void Display::drawLine(const Point2D &startPos, const Point2D &endPos)
{
    Point2D p1 = transformPoint(startPos);
    Point2D p2 = transformPoint(endPos);
    SDL_RenderDrawLine(mRenderer, p1.x, p1.y, p2.x, p2.y);
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

void Display::drawLines(const std::vector<std::vector<Point2D>> &dataPoint2D)
{
    if (dataPoint2D.size() > 1)
    {
        for (int i = 0; i < dataPoint2D.size() - 1; ++i)
        {
            drawLines(dataPoint2D[i]);
        }
    }
}

void Display::drawText(const std::string text, const Point2D pos, const double scale, const SDL_Color color, bool isCentered)
{
    SDL_Surface* surface = TTF_RenderText_Blended(mFontMain,text.c_str(), color);
    if(!surface)
    {
        std::cout<<"Surface not availabel \n";
        return;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(mRenderer, surface);
    if(!texture)
    {
        std::cout<<"texture not available \n";
        return;
    }
    int width = surface->w*scale;
    int height = surface->h*scale;
    int x = pos.x;
    int y = pos.y;
    // if(isCentered)
    // {
    //     x-=width/2;
    //     y-=height/2;
        
    // }
    SDL_Rect renderQuad = {x,y,width,height};
    SDL_RenderCopy(mRenderer, texture,nullptr,&renderQuad);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

Point2D Display::transformPoint(Point2D point)
{
    double dx = point.x - mViewXOffset;
    double dy = point.y - mViewYOffset;
    double y = mScreenHeight - (dx / mViewHeight) * mScreenHeight;
    double x = (dy / mViewWidth) * mScreenWidth;
    return Point2D(x, y);
}

void Display::setView(double width, double height, double xOffSet, double yOffset)
{
    mViewWidth = width;
    mViewHeight = height;
    mViewXOffset = xOffSet - mViewHeight / 2.0;
    mViewYOffset = yOffset - mViewWidth / 2.0;
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

void Display::generateGrid()
{
    gridTexture = SDL_CreateTexture(mRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 10*mScreenWidth, 10*mScreenHeight);

    // Set the render target to the texture
    SDL_SetRenderTarget(mRenderer, gridTexture);

    // Set the grid line color
    // SDL_SetRenderDrawColor(mRenderer, 30, 30, 30, 255); // dark gray
    // SDL_RenderClear(mRenderer);

    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255); // grid color
    int cellSize = 100;                                 // Example cell size
    double mGridSize = 1000;
    // Draw Horizontal lines
    for (double x = 0; x < 10*mScreenWidth; x += cellSize)
    {
        drawLine({x, 0}, {x, 10*mScreenHeight});
    }
    // for (double y = 0; y <10*mScreenHeight; y += cellSize)
    // {
    //     drawLine({0, y}, {10*mScreenWidth, y});
    // }

    // // Draw horizontal lines
    // for (int y = 0; y < mScreenWidth; y += cellSize)
    // {
    //     SDL_RenderDrawLine(mRenderer, 0, y, mScreenHeight, y);
    // }
    SDL_SetTextureBlendMode(gridTexture, SDL_BLENDMODE_BLEND);

    // Reset the render target back to the window
    SDL_SetRenderTarget(mRenderer, NULL);
    // SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255); // background
    // SDL_RenderClear(mRenderer);

    // In your main loop:
    // SDL_RenderClear(renderer); // Already cleared in the setup above if background is static

    // Draw other game objects here
    // SDL_RenderPresent(renderer);
}

void Display::renderGrid(int _x, int _y)
{
    SDL_Rect dst;
    // dst.x = (mViewYOffset- mViewWidth / 2);
    // dst.y = (mViewXOffset- mViewHeight / 2);
    auto pt = transformPoint({600,-380});
    dst.x =pt.x;
    dst.y = pt.y;
    dst.w = 10*mScreenWidth;
    dst.h = 10*mScreenWidth;
    SDL_RenderCopy(mRenderer, gridTexture, NULL, &dst); // study this function what is srcrect and what is dstrect
}