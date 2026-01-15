#pragma once

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

private:
    /* data */
};

Robot::Robot(/* args */)
{
}

Robot::~Robot()
{
}
