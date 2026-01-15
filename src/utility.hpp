#pragma once

struct Point2D
{
    double x,y;
    Point2D():x(0.0),y(0.0)
    {}
    Point2D(double _x, double _y):x(_x),y(_y){};
};