#include <solver.hpp>
#include <instance.hpp>
#include <fstream>

Instance::Instance(const std::string& path)
{
    std::ifstream file { path };
    int size = 0, read = 0;
    bool failed = false;

    if (!file) error("could not open ", path);

    file >> size >> optimum;

    for (int i = 0; i < size; ++i)
    {
        matrix.push_back({});

        for (int j = 0; j < size; ++j)
        {
            file >> read;
            if (!file) failed = true;
            matrix[matrix.size() - 1].push_back(read);
        }
    }

    if (failed) error("incomplete matrix in ", path);
}

int Instance::get_optimum() const
{
    return optimum;
}

int Instance::get_size() const
{
    return matrix.size();
}

int Instance::get_cost(int a, int b) const
{
    return matrix[a][b];
}