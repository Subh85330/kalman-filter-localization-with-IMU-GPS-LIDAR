#include "Robot.hpp"

Robot::Robot()
{
    mRobotBody = {{100,0.00},{500.0,500.0}};
}

Robot::~Robot()
{

}


void Robot::render(std::shared_ptr<Display> disp)
{
    disp->drawLine(mRobotBody[0], mRobotBody[1]);
}