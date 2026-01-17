#pragma once

struct RobotState
{
    double x, y, theta;
    double v, theta_dot;
    double steering;

    RobotState() : x(100.0), y(100.0), theta(0.0), v(0.0), theta_dot(0.0), steering(0.0) {}
    RobotState(double _x, double _y, double _theta) : x(_x), y(_y), theta(_theta), v(0.0), theta_dot(0.0), steering(0.0) {}
    RobotState(double _x, double _y, double _theta, double _v, double _theta_dot, double _steering) : x(_x), y(_y), theta(_theta), v(_v), theta_dot(_theta_dot), steering(_steering) {}
};

class Bicycle
{
public:
    Bicycle(/* args */);
    ~Bicycle();

    void update(double dt);
    RobotState getRobotState() const;
    void setVelocity(const double &velocity);
    void setSteering(const double &steering);

    double getVelocity();
    double getSteering();

private:
    RobotState mRobotState;
    double mVelocity;
    double mSteering;
    double mWheelBase;
    /* data */
};
