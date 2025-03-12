src_files = $(wildcard src/*.cpp)
obj_files = $(src_files:src/%.cpp=build/%.o)
test_files = $(wildcard tests/*.txt)
tests = $(test_files:%=%.test)
multitests = $(test_files:%=%.multitest)
flags = -g -std=c++17 -Wall -Wextra -Werror -pedantic
.PHONY: all test multitest

all: bin/solver

test: $(tests)

multitest: $(multitests)

%.test: % all
	bin/solver $<

%.multitest: % all
	python3 multitest.py $<

bin/solver: $(obj_files) | bin
	g++ -o bin/solver $(obj_files)

build/%.o: src/%.cpp include/*.hpp | build
	g++ $(flags) -c -Iinclude -o $@ $<

build/solver.o: config.hpp

bin:
	mkdir -p bin

build:
	mkdir -p build