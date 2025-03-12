#include <modular_mutation_maker.hpp>
#include <solver.hpp>

void NoMutationMaker::mutate(Solution& solution, std::mt19937_64& random) const
{
    (void) solution;
    (void) random;
}

void SwapMutationMaker::mutate(Solution& solution, std::mt19937_64& random) const
{
    int pos_1 = random() % solution.path.size(),
        pos_2 = random() % solution.path.size();

    int temp = solution.path[pos_1];
    solution.path[pos_1] = solution.path[pos_2];
    solution.path[pos_2] = temp;
}