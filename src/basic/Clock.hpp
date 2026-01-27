#pragma once

struct Time
{
    double hours, mins, secs;
    Time():hours(0.0),mins(0.0), secs(0.0)
    {}
};

class Clock
{
private:
    /* data */
    Time mTime;

public:
    Clock(/* args */);
    ~Clock();
    void setTime(Time time);
    Time getTime() const;
};


