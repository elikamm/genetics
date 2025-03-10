#include <modular_parent_chooser.hpp>

std::vector<std::pair<const Solution*, const Solution*>> RandomParentChooser::choose(const Population& population, std::default_random_engine& random) const
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