#include "utility.hpp"
#include <algorithm>
#include <cmath>

double wrapAngle(double angle)
{
    angle = fmod(angle, 2*M_PI);
    if(angle <= -M_PI){angle+=2*M_PI;}
    else if(angle > M_PI){angle-=2*M_PI;}
    return angle;
}


std::vector<Point2D> transformPoints(std::vector<Point2D> points, double x, double y, double rot)
{
    std::for_each(std::begin(points), std::end(points), [&](Point2D& p){
        auto xNew = p.x*cos(rot) - p.y*sin(rot) + x;
        p.y = p.x*sin(rot) + p.y*cos(rot) + y;
        p.x=xNew;

    });
    return points;
}

std::vector<Point2D> transformPoints(std::vector<Point2D> points, Point2D point, double rot)
{
    return transformPoints(points, point.x, point.y, rot);
}