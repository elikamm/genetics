#pragma once

#include <solution.hpp>

class MutationMaker
{
public:
    virtual void mutate(Solution& solution) const = 0;
};

class NoMutationMaker : public MutationMaker
{
public:
    void mutate(Solution& solution) const override;
};