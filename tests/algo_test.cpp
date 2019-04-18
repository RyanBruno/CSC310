#include <iostream>

#include "gtest/gtest.h"
#include "algo.hpp"

TEST(TestAlgo, TestTriangle) {

    std::array<Point, 3> polygon {{{0,0}, {1,2}, {2,0}}};
    std::array<float, 3> output;
    std::array<float, 3>::iterator output_it= output.begin();

    scanline<3>(polygon, 1, output_it);

    ASSERT_EQ(output[0], 1.5);
    ASSERT_EQ(output[1], .5);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
