#pragma once

#include <instance.hpp>
#include <solution.hpp>
#include <vector>

class Population
{
    int target_size;

public:
    explicit Population(int target_size) : target_size(target_size) {};

    std::vector<Solution> solutions;

    int get_target_size() const;
    const Solution& get_best_solution() const;
    const Solution& get_worst_solution() const;
};