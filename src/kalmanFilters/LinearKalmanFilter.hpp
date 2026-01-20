#pragma once
#include "KalmanFilterBase.hpp"


class LinearKalmanFilter : public KalmanFilterBase
{
public:
    LinearKalmanFilter();
    ~LinearKalmanFilter();
    void predictionStep(const double& dt);
    void handleGPSMeasurement(GPSMeasurement meas);
    
};
