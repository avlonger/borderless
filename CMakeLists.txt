cmake_minimum_required(VERSION 2.8.4)
project(unbordered_factors)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

set(EXPERIMENT src/average.cpp src/unbordered.cpp src/border.cpp)
set(COMPARE_ALGORITHMS src/compare_algorithms.cpp src/unbordered.cpp src/border.cpp)
add_executable(average ${EXPERIMENT})
add_executable(compare_algorithms ${COMPARE_ALGORITHMS})
