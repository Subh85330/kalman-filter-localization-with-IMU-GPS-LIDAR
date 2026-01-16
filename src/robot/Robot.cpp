#include "Robot.hpp"

Robot::Robot() : mBicycleModel(),mRobotCurrentState()
{
    mRobotLength = 50.0;
    mRobotWidth = 30.0;
    mRobotWheelBase = 40.0;
    mRobotBody = {{-mRobotLength/2,mRobotWidth/2},
                  {mRobotLength/2,mRobotWidth/2},
                  {mRobotLength,0},
                  {mRobotLength/2, -mRobotWidth/2},
                  {-mRobotLength/2, -mRobotWidth/2},
                  {-mRobotLength/2,mRobotWidth/2}};
    // mRobotBody = {{}};
    mWheelDims = {{-5,-2.5},{5,-2.5},{5,2.5},{-5,2.5},{-5,-2.5}};
    
    mLFWheelOffset = {mRobotLength/2, -mRobotWidth/2};
    mRFWheelOffset = {mRobotLength/2,mRobotWidth/2};

    mLRWheelOffset = {-mRobotLength/2,-mRobotWidth/2};
    mRRWheelOffset = {-mRobotLength/2,mRobotWidth/2};
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

RobotState Robot::getRobotCurrentState() const
{
    return mRobotCurrentState;
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