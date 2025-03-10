#include <modular_stopper.hpp>

TimeStopper::TimeStopper(long seconds)
{
    stop_time = std::time(nullptr) + seconds;
}

bool TimeStopper::should_stop()
{
    return stop_time < std::time(nullptr);
}

IterationStopper::IterationStopper(long iterations)
{
    remaining_iterations = iterations;
}

bool IterationStopper::should_stop()
{
    return (--remaining_iterations) < 0;
}