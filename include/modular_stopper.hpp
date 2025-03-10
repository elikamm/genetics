#pragma once

#include <ctime>

class Stopper
{
public:
    virtual bool should_stop() = 0;
};

class TimeStopper : public Stopper
{
    std::time_t stop_time;

public:
    TimeStopper(long seconds);

    bool should_stop() override;
};

class IterationStopper : public Stopper
{
    long remaining_iterations;

public:
    IterationStopper(long iterations);

    bool should_stop() override;
};