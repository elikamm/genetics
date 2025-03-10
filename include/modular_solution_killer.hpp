#pragma once

#include <population.hpp>
#include <instance.hpp>

class SolutionKiller
{
public:
    virtual void kill(Population& population) const = 0;
};

class WorstSolutionKiller : public SolutionKiller
{
public:
    void kill(Population& population) const override;
};