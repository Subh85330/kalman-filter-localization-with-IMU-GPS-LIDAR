#pragma once
#include <memory>
#include "../plotting/Display.hpp"

struct Time
{
    double hours, mins, secs;
    Time() : hours(0.0), mins(0.0), secs(0.0)
    {
    }
};

class Clock
{

public:
    Clock(/* args */);
    ~Clock();
    void setTime(double hours, double mins, double secs);
    Time getTime() const;
    void increaseTime(double hours, double mins, double secs);
    void decreaseTime(double hours, double mins, double secs);
    void render(std::shared_ptr<Display> disp);

private:
    /* data */
    Time mTime;
    int mTimemultiplier;
};
