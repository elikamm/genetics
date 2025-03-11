#include <modular_initial_generator.hpp>
#include <solver.hpp>
#include <algorithm>
    
Population RandomInitialGenerator::generate(const Instance& instance, std::mt19937_64& random) const
{
    Population population { population_size };

    int size = instance.get_size();

    for (int i = 0; i < population_size; ++i )
    {
        Solution solution;

        for (int i = 0; i < size; ++i) solution.path.push_back(i);

        std::shuffle(solution.path.begin(), solution.path.end(), random);

        population.solutions.push_back(solution);
    }

    return population;
}

Population HeuristicInitialGenerator::generate(const Instance& instance, std::mt19937_64& random) const
{
    Population population { population_size };

    (void) instance;
    (void) random;
    error("TODO: Implement RandomInitialGenerator");

    return population;
}

Population FixedInitialGenerator::generate(const Instance& instance, std::mt19937_64& random) const
{
    Population population { population_size };

    (void) instance;
    (void) random;
    error("TODO: Implement FixedInitialGenerator");

    return population;
}