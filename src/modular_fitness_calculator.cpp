#include <modular_fitness_calculator.hpp>

void AbsoluteFitnessCalculator::calculate(Population& population, const Instance& instance) const
{
    for (Solution& solution : population.solutions)
    {
        solution.fitness = (1000.0 / solution.get_cost(instance));
    }
}