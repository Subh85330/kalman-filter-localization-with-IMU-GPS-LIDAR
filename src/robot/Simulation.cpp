#include "Simulation.hpp"
#include <iostream>

#include "../kalmanFilters/ExtendedKF.hpp"

Simulation::Simulation() : mViewSize(1000), mSimStatus(SimStatus::NOT_STARTED)
{
    mSimParamsUptr = std::make_unique<SimulationParams>();
    mGrid = std::make_unique<Grid>();
    mRobotSptr = std::make_shared<Robot>();
    mKF = std::make_shared<LinearKalmanFilter>();
    mGPSSensor = std::make_shared<GPSSensor>();
}
Simulation::~Simulation()
{
}
void Simulation::update()
{
    if (!mIsPaused)
    {
        mRobotSptr->update(mSimParamsUptr->mTimeStep);
        RobotState robotCurrentState = mRobotSptr->getRobotCurrentState();
        mTrueTrajHistory.push_back({robotCurrentState.x, robotCurrentState.y});

        if (mSimParamsUptr->mGyroEnabled)
        {
            if (mSimParamsUptr->mGyroUpdateRemTime <= 0)
            {
                mKF->predictionStep(mSimParamsUptr->mTimeStep);
                mSimParamsUptr->mGyroUpdateRate += 1.0 / mSimParamsUptr->mGyroUpdateRate;
            }
            mSimParamsUptr->mGyroUpdateRemTime -= mSimParamsUptr->mTimeStep;
        }

        if (mSimParamsUptr->mGyroEnabled)
        {
            if (mSimParamsUptr->mGpsUpdateRemTime <= 0)
            {
                auto meas = mGPSSensor->generateGPSMeasurements(robotCurrentState.x, robotCurrentState.y);
                mKF->handleGPSMeasurement(meas);
                auto st = mKF->getStateVec();
                mEstimatedTrajHistory.push_back({st[0], st[1]});
                mSimParamsUptr->mGpsUpdateRemTime += 1.0 / mSimParamsUptr->mGpsUpdateRate;
            }
            mSimParamsUptr->mGpsUpdateRemTime -= mSimParamsUptr->mTimeStep;
        }

        mSimParamsUptr->mTimeNow += mSimParamsUptr->mTimeStep;
    }
}
void Simulation::setVelocity(const double &vel)
{
    mRobotSptr->setVelocity(vel);
}
void Simulation::setSteering(const double &steer)
{
    mRobotSptr->setSteering(steer);
}
void Simulation::increaseViewSize()
{
    if (mViewSize > 50)
    {
        mViewSize -= 25;
    }
}
void Simulation::decreaseViewSize()
{
    if (mViewSize < 3000)
    {
        mViewSize += 25;
    }
}
void Simulation::togglePause()
{
    mIsPaused = !mIsPaused;
}
double Simulation::getVelocity() const
{
    return mRobotSptr->getVelocity();
}
double Simulation::getSteering() const
{
    return mRobotSptr->getSteering();
}
void Simulation::render(std::shared_ptr<Display> disp)
{
    // disp->renderGrid(mRobotSptr->getRobotCurrentState().x, mRobotSptr->getRobotCurrentState().y);
    mRobotSptr->render(disp);
    disp->setView(mViewSize * disp->getScreenAspectRation(), mViewSize, mRobotSptr->getRobotCurrentState().x, mRobotSptr->getRobotCurrentState().y);
    // mGrid->render(disp, mRobotSptr->getRobotCurrentState().x, mRobotSptr->getRobotCurrentState().y);
    disp->setDrawColor(0, 255, 0, 255);
    disp->drawLines(mTrueTrajHistory);
    disp->setDrawColor(255, 0, 0, 255);
    disp->drawLines(mEstimatedTrajHistory);

    std::string timeString = stringFormat("Time: %0.2f", mSimParamsUptr->mTimeNow);
    disp->drawText(timeString, Point2D{0,0},1.0,{0,0,0},0);

}