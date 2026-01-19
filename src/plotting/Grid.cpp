#include "Grid.hpp"

Grid::Grid():mGridSpacing(100.0),mGridSize(1000)
{
    mGrid = {{}};
}

Grid::~Grid()
{
}

void Grid::generateGrid(double centerX, double centerY)
{
    
    // for(double x = -mGridSize; x<=mGridSize; x+=mGridSpacing)
    // {
    //     mGrid.push_back({{x,-mGridSize}, {x,mGridSize}});
    // }
    // for(double y = -mGridSize; y<=mGridSize; y+=mGridSpacing)
    // {
    //     mGrid.push_back({{-mGridSize,y}, {mGridSize,y}});
    // }

}

void Grid::render(const std::shared_ptr<Display> disp, double x, double y)
{
    generateGrid(x,y);
    disp->drawLines(mGrid);
}
