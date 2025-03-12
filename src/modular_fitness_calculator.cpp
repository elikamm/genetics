#include <modular_fitness_calculator.hpp>
#include <solver.hpp>

void AbsoluteFitnessCalculator::calculate(Population& population, const Instance& instance) const
{
    for (Solution& solution : population.solutions)
    {
        solution.fitness = (1000.0 / solution.get_cost(instance));
    }
}

void RelativeFitnessCalculator::calculate(Population& population, const Instance& instance) const
{
    int worst_cost = 0;

    for (auto& solution : population.solutions)
    {
        int cost = solution.get_cost(instance);

        if (cost > worst_cost) worst_cost = cost;
    }

    for (Solution& solution : population.solutions)
    {
        solution.fitness = worst_cost - solution.get_cost(instance);
    }
}