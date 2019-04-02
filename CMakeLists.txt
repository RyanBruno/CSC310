cmake_minimum_required(VERSION 3.1)

project(TheAlgorithm VERSION 1.0
                  DESCRIPTION "Project for csc 310"
                  LANGUAGES CXX)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest")

add_executable(TheAlgoithm src/main.cpp)
#add_executable(AlgoTesting tests/algo_test.cpp)
