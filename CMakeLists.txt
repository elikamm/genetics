cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SRCS src/*.cpp)

add_executable(solver ${SRCS})

target_include_directories(solver PUBLIC include)