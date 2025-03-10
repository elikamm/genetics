#pragma once

#include <instance.hpp>
#include <vector>

class Solution
{
public:
    std::vector<int> path;
    double fitness = 0;

    bool operator==(const Solution& other) const;
    bool operator<(const Solution& other) const;

    bool is_valid(const Instance& instance) const;
    int get_cost(const Instance& instance) const;
};