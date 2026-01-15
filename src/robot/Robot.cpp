#include "Robot.hpp"

Robot::Robot()
{
    mRobotBody = {{0.0,0.0},{50.0,0.0},{50,30},{0.0,30.0},{0,0}};
    // mRobotBody = {{}};
}

Robot::~Robot()
{

}

void Robot::render(std::shared_ptr<Display> disp)
{
    disp->drawLines(mRobotBody);
}