#pragma once

#include <solution.hpp>
#include <population.hpp>
#include <vector>
#include <utility>
#include <random>

class ParentChooser
{
public:
    virtual std::vector<std::pair<const Solution*, const Solution*>> choose(Population& population, std::mt19937_64& random) const = 0;
};

class RandomParentChooser : public ParentChooser
{
    int choose_count;

public:
    explicit RandomParentChooser(int choose_count) : choose_count(choose_count) {};

    std::vector<std::pair<const Solution*, const Solution*>> choose(Population& population, std::mt19937_64& random) const override;
};

class RouletteParentChooser : public ParentChooser
{
    int choose_count;

public:
    explicit RouletteParentChooser(int choose_count) : choose_count(choose_count) {};

    std::vector<std::pair<const Solution*, const Solution*>> choose(Population& population, std::mt19937_64& random) const override;
};

class RankedParentChooser : public ParentChooser
{
    int choose_count;

public:
    explicit RankedParentChooser(int choose_count) : choose_count(choose_count) {};

    std::vector<std::pair<const Solution*, const Solution*>> choose(Population& population, std::mt19937_64& random) const override;
};