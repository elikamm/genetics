#include <population.hpp>
#include <solver.hpp>

int Population::get_target_size() const
{
    return target_size;
}

const Solution& Population::get_best_solution() const
{
    if (solutions.size() == 0) error("population is empty");

    Solution const *best = &solutions[0];

    for (const Solution& solution : solutions)
        if (solution.fitness > best->fitness)
        {
            best = &solution;
        }

    return *best;
}

const Solution& Population::get_worst_solution() const
{
    if (solutions.size() == 0) error("population is empty");

    Solution const *worst = &solutions[0];

    for (const Solution& solution : solutions)
        if (solution.fitness < worst->fitness)
        {
            worst = &solution;
        }

    return *worst;
}