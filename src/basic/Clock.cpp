#include "Clock.hpp"
#include "../utility.hpp"

Clock::Clock(/* args */) : mTimemultiplier(1)
{
}

Clock::~Clock()
{
}

void Clock::setTime(double hours, double mins, double secs)
{
    mTime.hours = hours;
    mTime.mins = mins;
    mTime.secs = secs;
}

Time Clock::getTime() const
{
    return mTime;
}

void Clock::increaseTime(double hours, double mins, double secs)
{
    mTime.hours += hours;
    mTime.mins += mins;
    mTime.secs += secs;
}

void Clock::decreaseTime(double hours, double mins, double secs)
{
    mTime.hours -= hours;
    mTime.mins -= mins;
    mTime.secs -= secs;
}

void Clock::render(std::shared_ptr<Display> disp)
{
    std::string timeString = stringFormat("Time: %0.2f TimeMultiplier: %d", mTime.secs, mTimemultiplier);
    disp->drawText(timeString, Point2D{0, 0}, 1.0, {0, 0, 0}, 0);
}
