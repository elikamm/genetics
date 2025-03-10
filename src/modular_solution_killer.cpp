#include <modular_solution_killer.hpp>
#include <algorithm>
#include <solver.hpp>

void WorstSolutionKiller::kill(Population& population) const
{
    std::sort(population.solutions.begin(), population.solutions.end());

    int current_size = population.solutions.size(),
        target_size = population.get_target_size();

    if (current_size > target_size)
    {
        population.solutions.erase(
            population.solutions.begin(),
            population.solutions.begin() + (current_size - target_size)
        );
    }
}