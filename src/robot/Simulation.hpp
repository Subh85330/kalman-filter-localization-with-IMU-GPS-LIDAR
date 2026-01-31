#pragma once
#include "../kalmanFilters/LinearKalmanFilter.hpp"
#include "Robot.hpp"
#include "sensors/GPSSensor.hpp"
#include "../plotting/Grid.hpp"
#include "../basic/Clock.hpp"
#include "../basic/Shapes.hpp"

enum class SimStatus
{
    NOT_STARTED,
    RUNNING,
    FINISHED
};

struct SimulationParams
{
    double mTimeStep;
    // Gyro / Prediction
    double mGyroUpdateRate, mGyroUpdateRemTime;
    bool mGyroEnabled;

    // GPS
    double mGpsUpdateRate, mGpsUpdateRemTime;
    bool mGpsEnabled;

    SimulationParams()
        : mTimeStep(0.5),
          mGyroUpdateRate(0.10), mGyroUpdateRemTime(0.0), mGyroEnabled(true),
          mGpsUpdateRate(0.01), mGpsUpdateRemTime(0.0), mGpsEnabled(true)
    {
    }
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
    void increaseTimeMultiplier();
    void decreaseTimeMultiplier();
    void togglePause();

    double getVelocity() const;
    double getSteering() const;

    void render(const std::shared_ptr<Display>& disp);
    void reset();

private:
    SimStatus mSimStatus;
    bool mIsPaused;
    double mViewSize;
    double mTimeNow;
    Clock mClock;
    int mTimeMultiplier;
    std::unique_ptr<SimulationParams> mSimParamsUptr;
    std::unique_ptr<Grid> mGrid;
    std::shared_ptr<Robot> mRobotSptr;
    std::shared_ptr<KalmanFilterBase> mKF;
    std::shared_ptr<GPSSensor> mGPSSensor;
    std::vector<Point2D> mTrueTrajHistory;
    std::vector<Point2D> mEstimatedTrajHistory;
};
