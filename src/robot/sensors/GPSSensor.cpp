#include "GPSSensor.hpp"

GPSSensor::GPSSensor(/* args */):mRandGen(std::mt19937()),mStdD_gps(20)
{
}

GPSSensor::~GPSSensor()
{
}

GPSMeasurement GPSSensor::generateGPSMeasurements(double x, double y)
{
    GPSMeasurement meas;
    std::normal_distribution<double> gpsNorDis(0.0, mStdD_gps);
    meas.x = x + gpsNorDis(mRandGen);
    meas.y = y + gpsNorDis(mRandGen);
    return meas;
}