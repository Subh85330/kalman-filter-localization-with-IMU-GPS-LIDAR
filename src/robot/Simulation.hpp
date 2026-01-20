#pragma once
#include "../kalmanFilters/LinearKalmanFilter.hpp"
#include "Robot.hpp"
#include "sensors/GPSSensor.hpp"
#include "../plotting/Grid.hpp"

enum class SimStatus
{
    NOT_STARTED,
    RUNNING,
    FINISHED
};

struct SimulationParams
{
    double mTimeNow, mTimeStep;

    // Gyro / Prediction
    double mGyroUpdateRate, mGyroUpdateRemTime;
    bool mGyroEnabled;

    // GPS
    double mGpsUpdateRate, mGpsUpdateRemTime;
    bool mGpsEnabled;


    SimulationParams()
    :mTimeNow(0.0),mTimeStep(0.1),
    mGyroUpdateRate(10.0),mGyroUpdateRemTime(0.0),mGyroEnabled(true),
    mGpsUpdateRate(1.0),mGpsUpdateRemTime(0.0),mGpsEnabled(true)
    {}
};



class Simulation
{
public:
    Simulation(/* args */);
    ~Simulation();
    void update();

    void setVelocity(const double &vel);
    void setSteering(const double &steer);
    void increaseViewSize();
    void decreaseViewSize();
    void togglePause();

    double getVelocity() const;
    double getSteering() const;

    void render(std::shared_ptr<Display> disp);

private:
    SimStatus mSimStatus;
    bool mIsPaused;
    double mViewSize;
    std::unique_ptr<SimulationParams> mSimParamsUptr;
    std::unique_ptr<Grid> mGrid;
    std::shared_ptr<Robot> mRobotSptr;
    std::shared_ptr<KalmanFilterBase> mKF;
    std::shared_ptr<GPSSensor> mGPSSensor;
    std::vector<Point2D> mTrueTrajHistory;
    std::vector<Point2D> mEstimatedTrajHistory;

};
