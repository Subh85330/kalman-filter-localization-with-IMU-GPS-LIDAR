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

std::vector<Point2D> transformPoints(std::vector<Point2D> data, double x, double y, double rot)
{
    std::for_each(std::begin(data), std::end(data), [&](Point2D& p){
        auto xNew = p.x*cos(rot) - p.y*sin(rot) + x;
        auto yNew = p.x*sin(rot) + p.y*cos(rot) + y;
        p.x=xNew;
        p.y=yNew;
    });
    return data;
}