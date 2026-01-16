#pragma once
#include <vector>
struct Point2D
{
    double x,y;
    Point2D():x(0.0),y(0.0)
    {}
    Point2D(double _x, double _y):x(_x),y(_y){};
};
double wrapAngle(double angle);

std::vector<Point2D> transformPoints(std::vector<Point2D> points, double x, double y, double rot);
std::vector<Point2D> transformPoints(std::vector<Point2D> points, Point2D point, double rot=0);
