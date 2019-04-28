#include <iostream>

#include "gtest/gtest.h"
#include "algo.hpp"
#include "algo_test.cpp"

#include "emp_test.cpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
