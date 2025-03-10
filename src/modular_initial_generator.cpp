#include <modular_initial_generator.hpp>
#include <algorithm>
    
Population RandomInitialGenerator::generate(const Instance& instance, std::default_random_engine& random) const
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