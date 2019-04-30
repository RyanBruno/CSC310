cmake_minimum_required(VERSION 3.1)

project(TheAlgorithm VERSION 1.0
                  DESCRIPTION "Project for csc 310"
                  LANGUAGES CXX)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest")

add_executable(Empirical src/empirical.cpp)
target_include_directories(Empirical PRIVATE include/)

add_executable(TheAlgorithm src/main.cpp)
target_include_directories(TheAlgorithm PRIVATE include/)


add_executable(AlgoTests tests/test_main.cpp)
target_link_libraries(AlgoTests PRIVATE gtest)
target_include_directories(AlgoTests PRIVATE include/)

