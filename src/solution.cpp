#include <solution.hpp>
#include <algorithm>

bool Solution::operator==(const Solution& other) const
{
    return path == other.path;
}

bool Solution::operator<(const Solution& other) const
{
    return fitness < other.fitness;
}

bool Solution::is_valid(const Instance& instance) const
{
    if ((int)path.size() != instance.get_size()) return false;

    std::vector sorted = path;
    std::sort(sorted.begin(), sorted.end());

    for (int i = 0; i < (int)sorted.size(); ++i)
    {
        if (sorted[i] != i) return false;
    }

    return true;
}

int Solution::get_cost(const Instance& instance) const
{
    int cost = instance.get_cost(path[path.size() - 1], path[0]);

    for (int i = 0; i < (int)path.size() - 1; ++i)
    {
        cost += instance.get_cost(path[i], path[i + 1]);
    }

    return cost;
}