#include <modular_coupler.hpp>
#include <solver.hpp>
#include <algorithm>

Solution OnePointCoupler::couple(const std::pair<const Solution*, const Solution*>& parents, std::default_random_engine& random) const
{
    Solution child;

    int size = parents.first->path.size(),
        cut = random() % size;

    for (int i = 0; i < cut; ++i)
    {
        child.path.push_back(parents.first->path[i]);
    }

    for (int i = 0; i < size; ++i)
    {
        const int& current = parents.second->path[i];
        int already_inherited = false;

        for (int j = 0; j < cut; ++j)
            if (child.path[j] == current)
            {
                already_inherited = true;
            }

        if (!already_inherited)
        {
            child.path.push_back(current);
        }
    }

    return child;
}