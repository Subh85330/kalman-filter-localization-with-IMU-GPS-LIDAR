#pragma once



struct RobotState
{
    double x, y, theta;
    double v, theta_dot;
    double steering;

    RobotState() : x(0.0), y(0.0), theta(0.0), v(0.0), theta_dot(0.0), steering(0.0) {}
};


class Bicycle
{
public:
    Bicycle(/* args */);
    ~Bicycle();

    void update(double dt);
    RobotState getRobotState() const;
    void setVelocity(const double& velocity);
    void setSteering(const double& steering);

    double getVelocity();
    double getSteering();



private:
    RobotState mRobotState;
    double mVelocity;
    double mSteering;
    double mWheelBase;
    /* data */
    
};


