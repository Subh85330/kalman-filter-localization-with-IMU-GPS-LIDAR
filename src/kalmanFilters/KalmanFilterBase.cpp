#include "KalmanFilterBase.hpp"


KalmanFilterBase::KalmanFilterBase() : mIsInitilized(false)
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

void KalmanFilterBase::setIsInitilized(bool flag)
{
    mIsInitilized = flag;
}

bool KalmanFilterBase::getIsInitilized() const
{
    return mIsInitilized;
}

void KalmanFilterBase::handleGPSMeasurement(GPSMeasurement meas)
{

}