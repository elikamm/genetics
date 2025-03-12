#include <modular_parent_chooser.hpp>
#include <solver.hpp>
#include <algorithm>

std::vector<std::pair<const Solution*, const Solution*>> RandomParentChooser::choose(Population& population, std::mt19937_64& random) const
{
    std::vector<std::pair<const Solution*, const Solution*>> parents;

    int population_size = population.solutions.size();

    for (int i = 0; i < choose_count; ++i)
        parents.push_back(
            {
                &population.solutions[random() % population_size],
                &population.solutions[random() % population_size]
            }
        );

    return parents;
}

std::vector<std::pair<const Solution*, const Solution*>> RouletteParentChooser::choose(Population& population, std::mt19937_64& random) const
{
    std::vector<std::pair<const Solution*, const Solution*>> parents;

    double total_fitness = 0;
    for (const Solution& solution : population.solutions)
    {
        total_fitness += solution.fitness;
    }

    for (int i = 0; i < choose_count; ++i)
    {
        Solution const *parent_a;
        Solution const *parent_b;

        double roulette_a = (double)random() / random.max() * total_fitness,
            roulette_b = (double)random() / random.max() * total_fitness,
            interval_start = 0,
            interval_end = 0;

        for (const Solution& solution : population.solutions)
        {
            interval_start = interval_end;
            interval_end += solution.fitness;

            if (interval_start <= roulette_a && roulette_a <= interval_end)
                parent_a = &solution;

            if (interval_start <= roulette_b && roulette_b <= interval_end)
                parent_b = &solution;
        }

        parents.push_back({ parent_a, parent_b });
    }
    
    return parents;
}

struct ranked_solution
{
    Solution *solution;
    int rank;
};

std::vector<std::pair<const Solution*, const Solution*>> RankedParentChooser::choose(Population& population, std::mt19937_64& random) const
{
    std::vector<std::pair<const Solution*, const Solution*>> parents;

    int rank_count = ceil((double)population.solutions.size() / 10);

    double total_fitness = 0;
    for (const Solution& solution : population.solutions) total_fitness += solution.fitness;

    std::sort(population.solutions.begin(), population.solutions.end());

    std::vector<ranked_solution> ranked_solutions { population.solutions.size() };
    
    double rank_size = total_fitness / rank_count,
        current = 0;

    for (int i = 0; i < (int)ranked_solutions.size(); ++i)
    {
        ranked_solutions[i].solution = &population.solutions[i];
        ranked_solutions[i].rank = floor(current / rank_size);
        current += ranked_solutions[i].solution->fitness;
    }

    for (int i = 0; i < choose_count; ++i)
    {
        Solution const *parent_a = nullptr;
        Solution const *parent_b = nullptr;

        int rank_a = random() % rank_count,
            rank_b = random() % rank_count;

        for (auto& solution : ranked_solutions)
        {
            if (solution.rank == rank_a) {
                parent_a = solution.solution;
                solution.rank = -1;
            }
            if (solution.rank == rank_b) {
                parent_b = solution.solution;
                solution.rank = -1;
            }
        }

        if (parent_a != nullptr && parent_b != nullptr)
        {
            parents.push_back({ parent_a, parent_b });
        }
    }

    return parents;
}