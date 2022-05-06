cmake_minimum_required(VERSION 3.20)
project(TopoMap)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -fopenmp -lmlpack")

add_executable(TopoMap src/DisjointSets.hpp src/geomutils.cpp src/TopoMap.cpp src/main.cpp)
