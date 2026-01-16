#include "Robot.hpp"

Robot::Robot() : mBicycleModel(),mRobotCurrentState()
{
    mRobotBody = {{0.0,0.0},{50.0,0.0},{50,30},{0.0,30.0},{0,0}};
    // mRobotBody = {{}};
}

Robot::~Robot()
{

}

void Robot::update(double dt)
{
  mBicycleModel.update(dt);
  mRobotCurrentState = mBicycleModel.getRobotState();
}

void Robot::render(std::shared_ptr<Display> disp)
{   auto a = transformPoints(mRobotBody, mRobotCurrentState.x, mRobotCurrentState.y, mRobotCurrentState.theta);
    disp->drawLines(a);
}