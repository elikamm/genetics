#include <modular_mutation_maker.hpp>
#include <solver.hpp>

void NoMutationMaker::mutate(Solution& solution) const
{
    (void) solution;
}

void SwapMutationMaker::mutate(Solution& solution) const
{
    (void) solution;
    error("TODO: Implement SwapMutationMaker");
}