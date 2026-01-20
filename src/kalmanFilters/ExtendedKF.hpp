#pragma once
#include "KalmanFilterBase.hpp"
#include "../robot/sensors/GPSSensor.hpp"

class ExtendedKF : public KalmanFilterBase
{

public:
    ExtendedKF(/* args */);
    ~ExtendedKF();
    void predictionStep(const double &dt) override;

private:
    /* data */
};


