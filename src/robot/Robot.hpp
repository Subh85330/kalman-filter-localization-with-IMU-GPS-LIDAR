#pragma once
#include "../plotting/Display.hpp"
#include "../utility.hpp"
#include<vector>

struct RobotState
{
    double x,y,theta;
    double v, theta_dot;
    double steering;

    RobotState():x(0.0),y(0.0),theta(0.0),v(0.0),theta_dot(0.0),steering(0.0){}
};



class Robot
{

public:
    Robot(/* args */);
    ~Robot();
    void render(std::shared_ptr<Display> disp);
private:
    /* data */
    RobotState mRobotState;
    std::vector<Point2D>mRobotBody;
};

