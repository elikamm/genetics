#pragma once

#include <solution.hpp>
#include <utility>
#include <random>

class Coupler
{
public:
    virtual Solution couple(const std::pair<const Solution*, const Solution*>& parents, std::mt19937_64& random) const = 0;
};

class OnePointCoupler : public Coupler
{
public:
    Solution couple(const std::pair<const Solution*, const Solution*>& parents, std::mt19937_64& random) const override; 
};

class OrderCoupler : public Coupler
{
public:
    Solution couple(const std::pair<const Solution*, const Solution*>& parents, std::mt19937_64& random) const override; 
};

class OrderBasedCoupler : public Coupler
{
public:
    Solution couple(const std::pair<const Solution*, const Solution*>& parents, std::mt19937_64& random) const override; 
};