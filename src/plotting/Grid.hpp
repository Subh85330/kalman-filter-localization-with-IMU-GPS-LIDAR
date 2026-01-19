#pragma once

#include <vector>
#include "../utility.hpp"
#include "Display.hpp"

class Grid
{
private:
    double mGridSize;
    double mGridSpacing;
    std::vector<std::vector<Point2D>> mGrid;

public:
    Grid(/* args */);
    ~Grid();
    void generateGrid(double centerX, double centerY);

    void render(const std::shared_ptr<Display> disp, double x, double y);
};
