#pragma once

#include <vector>
#include <string>

class Instance
{
    int optimum;
    std::vector<std::vector<int>> matrix;

public:
    explicit Instance(const std::string& path);

    int get_size() const;
    int get_optimum() const;
    int get_cost(int a, int b) const;
};