#include "Simulation.hpp"
#include <iostream>

Simulation::Simulation() : mViewSize(500), mSimStatus(SimStatus::NOT_STARTED)
{
    mSimParamsUptr = std::make_unique<SimulationParams>();
    mGrid = std::make_unique<Grid>();
    mRobotSptr = std::make_shared<Robot>();
    mkf = std::make_shared<LinearKalmanFilter>();
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
                mkf->predictionStep(mSimParamsUptr->mTimeStep);
                mSimParamsUptr->mGyroUpdateRate += 1.0 / mSimParamsUptr->mGyroUpdateRate;
            }
            mSimParamsUptr->mGyroUpdateRemTime -= mSimParamsUptr->mTimeStep;
        }

        if (mSimParamsUptr->mGyroEnabled)
        {
            if (mSimParamsUptr->mGpsUpdateRemTime <= 0)
            {
                auto meas = mGPSSensor->generateGPSMeasurements(robotCurrentState.x, robotCurrentState.y);
                mkf->handleGPSMeasurement(meas);
                auto st = mkf->getStateVec();
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
    if (mViewSize < 1800)
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
    mRobotSptr->render(disp);
    disp->setView(mViewSize * disp->getScreenAspectRation(), mViewSize, mRobotSptr->getRobotCurrentState().x, mRobotSptr->getRobotCurrentState().y);
    mGrid->render(disp, mRobotSptr->getRobotCurrentState().x, mRobotSptr->getRobotCurrentState().y);
    disp->setDrawColor(0, 255, 0, 255);
    disp->drawLines(mTrueTrajHistory);
    disp->setDrawColor(255, 0, 0, 255);
    disp->drawLines(mEstimatedTrajHistory);
}
