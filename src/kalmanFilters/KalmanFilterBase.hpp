#pragma once
#include <Eigen/Dense>

using Eigen::VectorXd;

using Eigen::MatrixXd;

class KalmanFilterBase
{

public:
    KalmanFilterBase(/* args */);
    ~KalmanFilterBase();

    void setStateVec(const VectorXd &stateVec);
    void setCov(const VectorXd &covariance);

    VectorXd getStateVec() const;
    MatrixXd getCov() const;

private:
    VectorXd mStateVec;
    MatrixXd mCov;
};

