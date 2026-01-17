#pragma once
#include "../kalmanFilters/LinearKalmanFilter.hpp"
#include "Robot.hpp"
#include "sensors/GPSSensor.hpp"


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
    std::shared_ptr<LinearKalmanFilter> mkf;
    std::shared_ptr<GPSSensor> mGPSSensor;
    std::vector<Point2D> mTrueTrajHistory;
    std::vector<Point2D> mEstimatedTrajHistory;

    double dt;
};
