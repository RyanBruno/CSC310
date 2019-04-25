#include <iostream>

#include "gtest/gtest.h"
#include "algo.hpp"
#include <cstdlib>

TEST(TestAlgo, TestMaxMin) 
{
    const std::array<Point, 4> polygon = {{{0,0}, {0, 10}, {10,10}, {10, 0}}};
    auto result = scanline<4>(polygon);

    ASSERT_EQ(result.size() / 2, 9);
}

TEST(TestAlgo, TestPointX)
{
    const std::array<Point, 3> polygon = {{{0,0}, {10, 10}, {10,0}}};
    auto result = scanline<3>(polygon);

    ASSERT_EQ(result.size(), 18);

//    std::array<Point, 10> correct = {{{1,1}}};

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
