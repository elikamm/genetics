#pragma once

#include <instance.hpp>
#include <population.hpp>
#include <random>

class InitialGenerator
{
public:
    virtual Population generate(const Instance& instance, std::mt19937_64& random) const = 0;
};

class RandomInitialGenerator : public InitialGenerator
{
    int population_size;

public:
    explicit RandomInitialGenerator(int population_size) : population_size(population_size) {};

    Population generate(const Instance& instance, std::mt19937_64& random) const override;
};

class HeuristicInitialGenerator : public InitialGenerator
{
    int population_size;

public:
    explicit HeuristicInitialGenerator(int population_size) : population_size(population_size) {};

    Population generate(const Instance& instance, std::mt19937_64& random) const override;
};

class FixedInitialGenerator : public InitialGenerator
{
    int population_size;

public:
    explicit FixedInitialGenerator(int population_size) : population_size(population_size) {};

    Population generate(const Instance& instance, std::mt19937_64& random) const override;
};