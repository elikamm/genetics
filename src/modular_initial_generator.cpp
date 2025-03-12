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

    for (int i = 0; i < population_size; ++i)
    {
        Solution solution;

        solution.path = { (int)(random() % instance.get_size()) };

        for (int i = 1; i < instance.get_size(); ++i)
        {
            double lowest_cost = INFINITY;
            int next = -1;

            for (int j = 0; j < instance.get_size(); ++j)
            {
                double cost = instance.get_cost(solution.path[solution.path.size() - 1], j);

                if (std::find(solution.path.begin(), solution.path.end(), j) == solution.path.end() && cost < lowest_cost)
                {
                    lowest_cost = cost;
                    next = j;
                }
            }

            solution.path.push_back(next);
        }

        population.solutions.push_back(solution);
    }

    return population;
}

Population FixedInitialGenerator::generate(const Instance& instance, std::mt19937_64& random) const
{
    (void) random;

    Population population { population_size };

    std::vector<int> tour;

    for (int i = 0; i < instance.get_size(); ++i)
    {
        tour.push_back(i);
    }

    for (int i = 0; i < population_size; ++i)
    {
        Solution solution;

        solution.path = tour;

        population.solutions.push_back(solution);
    }

    return population;
}