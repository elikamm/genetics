src_files = $(wildcard src/*.cpp)
obj_files = $(src_files:src/%.cpp=build/%.o)
test_files = $(wildcard tests/*.txt)
tests = $(test_files:%=%.test)
flags = -g -std=c++17 -Wall -Wextra -Werror -pedantic
.PHONY: all test

all: bin/solver

test: $(tests)

%.test: % all
	bin/solver $<

bin/solver: $(obj_files) | bin
	g++ -o bin/solver $(obj_files)

build/%.o: src/%.cpp include/*.hpp | build
	g++ $(flags) -c -Iinclude -o $@ $<

build/solver.o: config.hpp

bin:
	mkdir -p bin

build:
	mkdir -p build