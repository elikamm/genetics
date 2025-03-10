#pragma once

#include <solution.hpp>
#include <utility>
#include <random>

class Coupler
{
public:
    virtual Solution couple(const std::pair<const Solution*, const Solution*>& parents, std::default_random_engine& random) const = 0;
};

class OnePointCoupler : public Coupler
{
public:
    Solution couple(const std::pair<const Solution*, const Solution*>& parents, std::default_random_engine& random) const override; 
};