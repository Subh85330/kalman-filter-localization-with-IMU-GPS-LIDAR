#include "Simulation.hpp"


Simulation::Simulation():dt(0.1)
{
    mRobotSptr = std::make_shared<Robot>();
}

Simulation::~Simulation()
{
}

void Simulation::update()
{
    mRobotSptr->update(dt);
    RobotState robotCurrentState = mRobotSptr->getRobotCurrentState();
    mTrueTrajHistory.push_back({robotCurrentState.x, robotCurrentState.y});
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
    disp->setDrawColor(0,255,0,255);
    disp->drawLines(mTrueTrajHistory);
}
