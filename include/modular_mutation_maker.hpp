#pragma once

#include <solution.hpp>
#include <random>

class MutationMaker
{
public:
    virtual void mutate(Solution& solution, std::mt19937_64& random) const = 0;
};

class NoMutationMaker : public MutationMaker
{
public:
    void mutate(Solution& solution, std::mt19937_64& random) const override;
};

class SwapMutationMaker : public MutationMaker
{
public:
    void mutate(Solution& solution, std::mt19937_64& random) const override;
};