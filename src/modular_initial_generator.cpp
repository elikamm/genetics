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
    (void) random;

    Population population { population_size };

    std::vector<int> tour = { 0 };

    for (int i = 1; i < instance.get_size(); ++i)
    {
        double lowest_cost = INFINITY;
        int next = -1;

        for (int j = 1; j < instance.get_size(); ++j)
        {
            double cost = instance.get_cost(tour[tour.size() - 1], j);

            if (std::find(tour.begin(), tour.end(), j) == tour.end() && cost < lowest_cost)
            {
                lowest_cost = cost;
                next = j;
            }
        }

        tour.push_back(next);
    }

    for (int i = 0; i < population_size; ++i)
    {
        Solution solution;

        solution.path = tour;

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