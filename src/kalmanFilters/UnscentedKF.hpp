#include "KalmanFilterBase.hpp"


class UnscentedKF : public KalmanFilterBase
{
private:
    /* data */
public:
    UnscentedKF(/* args */);
    ~UnscentedKF();
    void predictionStep(const double &dt) override;
    void handleGPSMeasurement(GPSMeasurement meas) override;
};
