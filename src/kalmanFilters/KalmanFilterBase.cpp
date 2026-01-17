#include "KalmanFilterBase.hpp"


KalmanFilterBase::KalmanFilterBase()
{
}

KalmanFilterBase::~KalmanFilterBase()
{
}

void KalmanFilterBase::setStateVec(const VectorXd &stateVec)
{
    mStateVec = stateVec;
}

void KalmanFilterBase::setCov(const MatrixXd &covariance)
{
    mCov = covariance;
}

VectorXd KalmanFilterBase::getStateVec() const
{
    return mStateVec;
}

MatrixXd KalmanFilterBase::getCov() const
{
    return mCov;
}
