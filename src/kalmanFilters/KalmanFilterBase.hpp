#pragma once
#include <Eigen/Dense>
#include "../robot/sensors/GPSSensor.hpp"
using Eigen::Vector2d;
using Eigen::Vector4d;
using Eigen::VectorXd;

using Eigen::Matrix2d;
using Eigen::Matrix4d;
using Eigen::MatrixXd;

class KalmanFilterBase
{

public:
    KalmanFilterBase(/* args */);
    ~KalmanFilterBase();

    VectorXd getStateVec() const;
    MatrixXd getCov() const;
    void setIsInitilized(bool flag);

    virtual void predictionStep(const double &dt) = 0;
    virtual void handleGPSMeasurement(GPSMeasurement meas);
    bool getIsInitilized() const;

protected:
    void setStateVec(const VectorXd &stateVec);
    void setCov(const MatrixXd &covariance);

private:
    VectorXd mStateVec;
    MatrixXd mCov;
    bool mIsInitilized;
};
