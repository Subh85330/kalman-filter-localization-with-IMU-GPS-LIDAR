#include "Robot.hpp"

Robot::Robot() : mBicycleModel(),mRobotCurrentState()
{
    mRobotLength = 50.0;
    mRobotWidth = 30.0;
    mRobotWheelBase = 40.0;
    mRobotBody = {{0.0,0.0},
                  {mRobotLength,0.0},
                  {mRobotLength, mRobotWidth},
                  {0.0, mRobotWidth},
                  {0,0}};
    // mRobotBody = {{}};
    mWheelDims = {{0,0},{10,0},{10,5},{0,5},{0,0}};
    
    mLFWheelOffset = {40,30};
    mRFWheelOffset = {40,-5};
    mLRWheelOffset = {0,30};
    mRRWheelOffset = {0,-5};
}

Robot::~Robot()
{

}


void Robot::setVelocity(double velocity)
{
    mBicycleModel.setVelocity(velocity);
}

void Robot::setSteering(double steering)
{
    mBicycleModel.setSteering(steering);
}

double Robot::getVelocity()
{
    return mBicycleModel.getVelocity();
}

double Robot::getSteering()
{
    return mBicycleModel.getSteering();
}



void Robot::update(double dt)
{
  mBicycleModel.update(dt);
  mRobotCurrentState = mBicycleModel.getRobotState();
}

void Robot::render(std::shared_ptr<Display> disp)
{ 
    disp->drawLines(transformPoints(mRobotBody, mRobotCurrentState.x, mRobotCurrentState.y, mRobotCurrentState.theta));
    disp->drawLines(transformPoints(transformPoints(mWheelDims, mRRWheelOffset), mRobotCurrentState.x, mRobotCurrentState.y, mRobotCurrentState.theta));
    disp->drawLines(transformPoints(transformPoints(mWheelDims, mLRWheelOffset), mRobotCurrentState.x, mRobotCurrentState.y, mRobotCurrentState.theta));
    disp->drawLines(transformPoints(transformPoints(mWheelDims, mRFWheelOffset), mRobotCurrentState.x, mRobotCurrentState.y, mRobotCurrentState.theta));
    disp->drawLines(transformPoints(transformPoints(mWheelDims, mLFWheelOffset), mRobotCurrentState.x, mRobotCurrentState.y, mRobotCurrentState.theta));
}