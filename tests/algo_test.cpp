#include <iostream>

#include "gtest/gtest.h"
#include "algo.hpp"
#include <cstdlib>

template <int I> void generate_polygon(std::array<Point, I>& polygon);


TEST(TestAlgo, TestTriangle) 
{
    std::array<Point, 3> polygon;
//    scanline<3>(polygon, output_it);

}

template <int I>
void generate_polygon(
        std::array<Point, I>& polygon)
{
    std::for_each(polygon.begin(), polygon.end(), [](Point& p)
    {
        std::srand(std::time(nullptr));
        p.x = std::rand() % 1000;
        EXPECT_TRUE(false) << p.x;
        p.y = std::rand() % 1000;
        EXPECT_TRUE(false) << p.y;
    });
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
