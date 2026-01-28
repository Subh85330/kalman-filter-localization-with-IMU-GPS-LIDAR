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
    void decreaseTimeMultiplier();
    void increaseTimeMultiplier();

    Time getTime() const;
    int getTimeMultiplier() const;

    void increaseTime(double hours, double mins, double secs);
    void decreaseTime(double hours, double mins, double secs);
    void formatTime();
    void render(const std::shared_ptr<Display>& disp);
    void reset();
private:
    /* data */
    Time mTime;
    int mTimeMultiplier;
};
