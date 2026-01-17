#include "Simulation.hpp"
#include <iostream>

Simulation::Simulation() : dt(0.5)
{
    mRobotSptr = std::make_shared<Robot>();
    mkf = std::make_shared<LinearKalmanFilter>();
    mGPSSensor = std::make_shared<GPSSensor>();
}

Simulation::~Simulation()
{
}

void Simulation::update()
{
    mRobotSptr->update(dt);
    RobotState robotCurrentState = mRobotSptr->getRobotCurrentState();
    mTrueTrajHistory.push_back({robotCurrentState.x, robotCurrentState.y});

    mkf->predictionStep(dt);

    auto meas = mGPSSensor->generateGPSMeasurements(robotCurrentState.x, robotCurrentState.y);
    mkf->handleGPSMeasurement(meas);
    auto st = mkf->getStateVec();
    mEstimatedTrajHistory.push_back({st[0], st[1]});
}

void Simulation::setVelocity(const double &vel)
{
    mRobotSptr->setVelocity(vel);
}

void Simulation::setSteering(const double &steer)
{
    mRobotSptr->setSteering(steer);
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
    // disp->setDrawColor(0, 255, 0, 255);
    // disp->drawLines(mTrueTrajHistory);
    disp->setDrawColor(255, 0, 0, 255);
    disp->drawLines(mEstimatedTrajHistory);
}
