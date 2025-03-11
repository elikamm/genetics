#include <modular_parent_chooser.hpp>
#include <solver.hpp>

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

std::vector<std::pair<const Solution*, const Solution*>> RouletteParentChooser::choose(const Population& population, std::default_random_engine& random) const
{
    std::vector<std::pair<const Solution*, const Solution*>> parents;

    (void) choose_count;
    (void) population;
    (void) random;
    error("TODO: Implement RouletteParentChooser");

    return parents;
}

std::vector<std::pair<const Solution*, const Solution*>> RankedParentChooser::choose(const Population& population, std::default_random_engine& random) const
{
    std::vector<std::pair<const Solution*, const Solution*>> parents;

    (void) choose_count;
    (void) population;
    (void) random;
    error("TODO: Implement RankedParentChooser");

    return parents;
}