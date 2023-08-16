cmake_minimum_required(VERSION 3.21)
project(SimplifiedPageRank)

set(CMAKE_CXX_STANDARD 14)

add_executable(SimplifiedPageRank test-unit/test.cpp src/AdjacencyList.cpp src/AdjacencyList.h)
