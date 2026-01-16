#include "KalmanFilterBase.hpp"


KalmanFilterBase::KalmanFilterBase(/* args */)
{
}

KalmanFilterBase::~KalmanFilterBase()
{
}

inline void KalmanFilterBase::setStateVec(const VectorXd &stateVec)
{
    mStateVec = stateVec;
}

void KalmanFilterBase::setCov(const VectorXd &covariance)
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
