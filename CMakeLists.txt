cmake_minimum_required(VERSION 2.8.4)
project(borderless_factors)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

set(EXPERIMENT src/average.cpp src/borderless.cpp src/border.cpp)
set(COMPARE_ALGORITHMS src/compare_algorithms.cpp src/borderless.cpp src/border.cpp)
add_executable(experiment ${EXPERIMENT})
add_executable(compare_algorithms ${COMPARE_ALGORITHMS})
