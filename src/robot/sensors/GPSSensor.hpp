#pragma once
#include<random>

struct GPSMeasurement
{
    double x, y;
    GPSMeasurement():x(0.0), y(0.0){}
    GPSMeasurement(int _x, int _y):x(_x),y(_y){}
};

class GPSSensor
{

public:
    GPSSensor(/* args */);
    ~GPSSensor();
    GPSMeasurement generateGPSMeasurements(double x, double y);
private:
    // GPSMeasurement trueMeas;
    double mStdD_gps;
    std::mt19937 mRandGen;

};




