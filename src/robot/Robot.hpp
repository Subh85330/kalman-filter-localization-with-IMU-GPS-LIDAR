#pragma once
#include <vector>

#include "../plotting/Display.hpp"
#include "../utility.hpp"

#include "Bicycle.hpp"


class Robot
{
public:
    Robot(/* args */);
    ~Robot();
    void setVelocity(double velocity);
    void setSteering(double steering);
    double getVelocity();
    double getSteering();
    RobotState getRobotCurrentState() const;

    void update(double dt);
    void render(std::shared_ptr<Display> disp);

private:
    double mRobotLength;
    double mRobotWidth;
    double mRobotWheelBase;
    Bicycle mBicycleModel;
    RobotState mRobotCurrentState;
    std::vector<Point2D> mRobotBody;
    std::vector<Point2D> mWheelDims;
    Point2D mLFWheelOffset;
    Point2D mRFWheelOffset;
    Point2D mLRWheelOffset;
    Point2D mRRWheelOffset;

};
