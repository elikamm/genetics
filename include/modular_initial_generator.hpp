#pragma once

#include <instance.hpp>
#include <population.hpp>
#include <random>

class InitialGenerator
{
public:
    virtual Population generate(const Instance& instance, std::default_random_engine& random) const = 0;
};

class RandomInitialGenerator : public InitialGenerator
{
    int population_size;

public:
    explicit RandomInitialGenerator(int population_size) : population_size(population_size) {};

    Population generate(const Instance& instance, std::default_random_engine& random) const override;
};