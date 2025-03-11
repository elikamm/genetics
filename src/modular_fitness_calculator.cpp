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
    (void) population;
    (void) instance;
    error("TODO: Implement RelativeFitnessCalculator");
}