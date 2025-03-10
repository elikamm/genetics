#pragma once

#include <population.hpp>
#include <instance.hpp>

class FitnessCalculator
{
public:
    virtual void calculate(Population& population, const Instance& instance) const = 0;
};

class AbsoluteFitnessCalculator : public FitnessCalculator
{
public:
    void calculate(Population& population, const Instance& instance) const override;
};