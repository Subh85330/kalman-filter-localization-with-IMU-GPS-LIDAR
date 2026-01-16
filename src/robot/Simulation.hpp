#pragma once

#include "Robot.hpp"

class Simulation
{
public:
    Simulation(/* args */);
    ~Simulation();
    void update();

    void setVelocity(const double &vel);
    void setSteering(const double &steer);

    double getVelocity() const;
    double getSteering() const;

    void render(std::shared_ptr<Display> disp);

private:
    std::shared_ptr<Robot> mRobotSptr;
    std::vector<Point2D> mTrueTrajHistory;

    double dt;
};
