#include "Clock.hpp"
#include "../utility.hpp"

Clock::Clock(/* args */) : mTimeMultiplier(1)
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

void Clock::decreaseTimeMultiplier()
{
    if (mTimeMultiplier > 1)
    {
        mTimeMultiplier -= 1;
    }
}
void Clock::increaseTimeMultiplier()
{
    mTimeMultiplier+=1;
}

Time Clock::getTime() const
{
    return mTime;
}

int Clock::getTimeMultiplier() const
{
    return mTimeMultiplier;
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

void Clock::formatTime()
{
    if(mTime.secs >60)
    {
        mTime.mins+=1;
        mTime.secs=0;
    }
    
    if(mTime.mins >60)
    {
        mTime.hours+=1;
        mTime.mins=0;
    }
    
}

void Clock::render(const std::shared_ptr<Display>& disp)
{
    std::string timeString = stringFormat("Time %0.2f:%0.2f:%0.2f", mTime.hours, mTime.mins, mTime.secs);
    disp->drawText(timeString, Point2D{0, 0});
    std::string multiplier = stringFormat("TimeMultiplier: %d", mTimeMultiplier);
    disp->drawText(multiplier, Point2D{0, 30});
}

void Clock::reset()
{   
    mTime.secs=0;
    mTime.hours=0;
    mTime.mins=0;
    mTimeMultiplier=1;
}
