#pragma once
#include "KalmanFilterBase.hpp"
#include "../robot/sensors/GPSSensor.hpp"

class LinearKalmanFilter : public KalmanFilterBase
{
public:
    LinearKalmanFilter();
    ~LinearKalmanFilter();
    void predictionStep(const double& dt);
    void handleGPSMeasurement(GPSMeasurement meas);

    void setIsInitilized(bool flag);
    bool getIsInitilized() const;

private:
    bool mIsInitilized;
    
};
