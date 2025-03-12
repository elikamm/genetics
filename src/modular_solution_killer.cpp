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

void WorseThanBestSolutionKiller::kill(Population& population) const
{
    std::sort(population.solutions.begin(), population.solutions.end());

    double threshold = population.solutions[population.solutions.size() - 1].fitness * .9;

    int last_good;

    for (int i = population.solutions.size() - 1; i >= 0; --i)
    {
        if (population.solutions[i].fitness >= threshold)
            last_good = i;
        else
            break;
    }

    population.solutions.erase(
        population.solutions.begin(),
        population.solutions.begin() + last_good
    );
}