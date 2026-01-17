#pragma once
#include <Eigen/Dense>

using Eigen::VectorXd;
using Eigen::Vector2d;
using Eigen::Vector4d;

using Eigen::MatrixXd;
using Eigen::Matrix2d;
using Eigen::Matrix4d;

class KalmanFilterBase
{

public:
    KalmanFilterBase(/* args */);
    ~KalmanFilterBase();

    void setStateVec(const VectorXd &stateVec);
    void setCov(const MatrixXd &covariance);

    VectorXd getStateVec() const;
    MatrixXd getCov() const;

private:
    VectorXd mStateVec;
    MatrixXd mCov;
};

