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

    void update(double dt);
    void render(std::shared_ptr<Display> disp);

private:
    Bicycle mBicycleModel;
    RobotState mRobotCurrentState;
    std::vector<Point2D> mRobotBody;
};
