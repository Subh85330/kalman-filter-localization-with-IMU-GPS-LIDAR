#include "Bicycle.hpp"
#include <cmath>
#include "../utility.hpp"

Bicycle::Bicycle(/* args */):mWheelBase(25),mVelocity(0.1),mSteering(0.1)
{
}

Bicycle::~Bicycle()
{
}

void Bicycle::update(double dt)
{
    mRobotState.v = mVelocity;
    mRobotState.steering =mSteering;
    mRobotState.x += dt*mRobotState.v*cos(mRobotState.theta);
    mRobotState.y += dt*mRobotState.v*sin(mRobotState.theta);
    mRobotState.theta_dot = (mRobotState.v*mRobotState.steering)/mWheelBase;
    mRobotState.theta += mRobotState.theta_dot*dt;
    mRobotState.theta = wrapAngle(mRobotState.theta);
}

RobotState Bicycle::getRobotState() const
{
    return mRobotState;
}

void Bicycle::setVelocity(const double& velocity)
{
    mVelocity = velocity;
}
void Bicycle::setSteering(const double& steering)
{
    mSteering = steering;
}

double Bicycle::getVelocity()
{
    return mVelocity;
}
double Bicycle::getSteering()
{
    return mSteering;
}