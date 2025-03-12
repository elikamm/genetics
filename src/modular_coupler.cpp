#include <modular_coupler.hpp>
#include <solver.hpp>
#include <algorithm>

Solution OnePointCoupler::couple(const std::pair<const Solution*, const Solution*>& parents, std::mt19937_64& random) const
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

Solution OrderCoupler::couple(const std::pair<const Solution*, const Solution*>& parents, std::mt19937_64& random) const
{
    Solution child;

    int size = parents.first->path.size(),
        cut_a = random() % size,
        cut_b = random() % size;

    if (cut_b > cut_a)
    {
        int temp = cut_a;
        cut_a = cut_b;
        cut_b = temp;
    }

    for (int i = 0; i < size; ++i)
    {
        int node = -1;
        
        if (cut_a < i && i < cut_b)
        {
            node = parents.first->path[i];
        }

        child.path.push_back(node);
    }

    int child_index = cut_b,
        parent_index = cut_b;

    while (child.path[child_index] == -1)
    {
        while (std::find(child.path.begin(), child.path.end(), parents.second->path[parent_index]) != child.path.end())
        {
            parent_index = (parent_index + 1) % size;
        }

        child.path[child_index] = parents.second->path[parent_index];

        child_index = (child_index + 1) % size;
    }

    return child;
}

Solution OrderBasedCoupler::couple(const std::pair<const Solution*, const Solution*>& parents, std::mt19937_64& random) const
{
    Solution child;
    child.path = parents.second->path;

    int size = parents.first->path.size();

    std::vector<int> values;

    for (int i = 0; i < size; ++i)
        if ((double)random() / random.max() < .5)
        {
            values.push_back(parents.first->path[i]);
        }

    std::vector<int> positions;
    
    for (int i = 0; i < size; ++i)
        if (std::find(values.begin(), values.end(), parents.second->path[i]) != values.end())
        {
            positions.push_back(i);
        }

    for (int i = 0; i < (int)values.size(); ++i)
    {
        child.path[positions[i]] = values[i];
    }

    return child;
}