#define CURRENT_TIME std::chrono::system_clock::now().time_since_epoch().count()
#include "../config.hpp"

#include <solver.hpp>
#include <instance.hpp>
#include <population.hpp>
#include <modular_coupler.hpp>
#include <modular_fitness_calculator.hpp>
#include <modular_initial_generator.hpp>
#include <modular_mutation_maker.hpp>
#include <modular_parent_chooser.hpp>
#include <modular_solution_killer.hpp>
#include <modular_stopper.hpp>
#include <chrono>

int main(int argc, char **argv)
{
    if (argc < 2) error("missing instance");

    Instance instance { argv[1] };
    info("solving ", argv[1], " (size ", instance.get_size(), ')');

    std::mt19937_64 random;
    random.seed(SEED);

    COUPLER coupler {};
    FITNESS_CALCULATOR fitness_calculator {};
    INITIAL_GENERATOR initial_generator { POPULATION_SIZE };
    MUTATION_MAKER mutation_maker {};
    PARENT_CHOOSER parent_chooser { PARENT_COUNT };
    SOLUTION_KILLER solution_killer {};
    STOPPER stopper { STOPPER_DURATION };

    Population population = initial_generator.generate(instance, random);

    while (!stopper.should_stop())
    {
        fitness_calculator.calculate(population, instance);

        solution_killer.kill(population);

        std::vector<Solution> children;

        for (const auto& parents : parent_chooser.choose(population, random))
        {
            Solution child = coupler.couple(parents, random);

            mutation_maker.mutate(child);

            children.push_back(child);
        }

        population.solutions.insert(population.solutions.end(), children.begin(), children.end());
    }

    double best = population.get_best_solution().get_cost(instance),
        optimum = instance.get_optimum();
    result(best, " (optimum ", optimum, " + ", (best / optimum - 1) * 100, "%)");

    return 0;
}