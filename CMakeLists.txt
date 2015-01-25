cmake_minimum_required(VERSION 2.8.4)
project(borderless_factors)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

set(EXPERIMENT src/average.cpp src/period.cpp src/border.cpp)
set(MEASURE src/measure.cpp src/period.cpp src/border.cpp)
add_executable(experiment ${EXPERIMENT})
add_executable(measure ${MEASURE})
