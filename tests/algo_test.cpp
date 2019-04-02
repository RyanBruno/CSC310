#include <iostream>

#include "gtest/gtest.h"
#include "algo.hpp"

TEST(TestGTest, TestGTestInit) {
  ASSERT_TRUE(true);
}

TEST(TestAlgo, TestAdding) {
  ASSERT_TRUE(add(5, 6) == 11);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
