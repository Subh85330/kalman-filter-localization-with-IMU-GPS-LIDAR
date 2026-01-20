#include "LinearKalmanFilter.hpp"
#include <iostream>

constexpr bool INIT_ON_FIRST_PREDICTION = false;
constexpr double INIT_POS_STD = 0;
constexpr double INIT_VEL_STD = 15;
constexpr double ACCEL_STD = 0.1;
constexpr double GPS_POS_STD = 3.0;

LinearKalmanFilter::LinearKalmanFilter()
{
}

LinearKalmanFilter::~LinearKalmanFilter()
{
}

void LinearKalmanFilter::predictionStep(const double &dt)
{
    if (!getIsInitilized())
    {
        VectorXd state = Vector4d::Zero();
        state << 100, 100, 0.1, 0;
        MatrixXd cov = Matrix4d::Zero();
        cov(0, 0) = INIT_POS_STD * INIT_POS_STD;
        cov(1, 1) = INIT_POS_STD * INIT_POS_STD;
        cov(2, 2) = INIT_VEL_STD * INIT_VEL_STD;
        cov(3, 3) = INIT_VEL_STD * INIT_VEL_STD;
        setIsInitilized(true);
        setStateVec(state);
        setCov(cov);
    }
    else
    {
        VectorXd state = getStateVec();
        MatrixXd cov = getCov();

        MatrixXd F = Matrix4d();
        F << 1, 0, dt, 0, 0, 1, 0, dt, 0, 0, 1, 0, 0, 0, 0, 1;

        MatrixXd L = MatrixXd(4, 2);
        L << (0.5 * dt * dt), 0, 0, (0.5 * dt * dt), dt, 0, 0, dt;

        MatrixXd Q = Matrix2d::Zero();
        Q(0, 0) = (ACCEL_STD * ACCEL_STD);
        Q(1, 1) = (ACCEL_STD * ACCEL_STD);

        state = F * state;
        cov = F * cov * F.transpose() + L * Q * L.transpose();
        setStateVec(state);
        setCov(cov);
    }
}

void LinearKalmanFilter::handleGPSMeasurement(GPSMeasurement meas)
{
    if (getIsInitilized())
    {
        auto state = getStateVec();
        auto cov = getCov();

        VectorXd z = Vector2d();
        MatrixXd H = MatrixXd(2, 4);
        MatrixXd R = Matrix2d::Zero();

        z << meas.x, meas.y;
        H << 1, 0, 0, 0, 0, 1, 0, 0;
        R(0, 0) = GPS_POS_STD * GPS_POS_STD;
        R(1, 1) = GPS_POS_STD * GPS_POS_STD;

        VectorXd zHat = H * state;
        VectorXd y = z - zHat;
        MatrixXd S = H * cov * H.transpose() + R;
        MatrixXd K = cov * H.transpose() * S.inverse();

        state = state + K * y;
        cov = (MatrixXd::Identity(4,4) - K * H) * cov;

        setStateVec(state);
        setCov(cov);
    }
}


