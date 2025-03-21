# 🧬 Genetics
A set of genetic algorithms for the TSP.

## Config
Edit the __'config.hpp'__ file to modify parameters and implementations of the solver.

## Build
Run `make` from the repository root. This will build the executable __'solver'__ (inside a __'bin'__ directory).

Alternatively create a __'build'__ directory and run `cmake ..` and `cmake --build .` from there. This will build the executable __'solver'__ (inside that directory)  
**WARNING:** Notice that the makefile targets and __'multitest.py'__ do not work with CMake.

## Build and Test
Run `make test` from the repository root. This will build the executable and run it with each instance from the __'tests'__ directory.

## Multitest
Run `python3 multitest.py <instance>` from the repository root. This will test every combination of parameters and implementations on a given instance (and store the results to a __'results\_&lt;instance&gt;.txt'__ file).

## Multitest all
Run `make multitest` from the repository root. This will test every combination of parameters and implementations on all instances.