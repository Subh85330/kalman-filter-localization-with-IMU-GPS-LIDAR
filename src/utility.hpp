#pragma once
#include <vector>
#include <string>
#include <memory>

struct Point2D
{
    double x,y;
    Point2D():x(0.0),y(0.0)
    {}
    Point2D(double _x, double _y):x(_x),y(_y){};
};
double wrapAngle(double angle);

std::vector<Point2D> transformPoints(std::vector<Point2D> points, double x, double y, double rot=0.0);
std::vector<Point2D> transformPoints(std::vector<Point2D> points, Point2D point, double rot=0);

template<typename ... Params>
std::string stringFormat(const std::string& format, Params ... params)
{
    size_t size = snprintf(nullptr, 0, format.c_str(), params ...)+1;
    if(size <=0){throw std::runtime_error("Error during formating.");}
    std::unique_ptr<char[]> buff(new char[size]);
    snprintf(buff.get(), size, format.c_str(), params ...);
    return std::string(buff.get(), buff.get()+size);
}