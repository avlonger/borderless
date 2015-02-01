cmake_minimum_required(VERSION 2.8.4)
project(unbordered_factors)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

set(AVERAGE src/average.cpp src/unbordered.cpp src/border.cpp src/dbf.cpp src/etc.cpp)
set(COMPARE_ALGORITHMS src/compare_algorithms.cpp src/unbordered.cpp src/border.cpp src/dbf.cpp src/etc.cpp)
add_executable(average ${AVERAGE})
add_executable(compare_algorithms ${COMPARE_ALGORITHMS})
