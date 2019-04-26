#include <iostream>

#include "gtest/gtest.h"
#include "algo.hpp"
#include "algo_test.cpp"

/*
template <int I>
void generate_polygon(
        std::array<Point, I>& polygon, const int& n)
{
    std::for_each(polygon.begin(), polygon.end(), [&](Point& p)
    {
        std::srand(std::time(nullptr));
        p.x = std::rand() % 1000;
        EXPECT_TRUE(false) << p.x;
        p.y = std::rand() % n;
        EXPECT_TRUE(false) << p.y;
    });
}

#include "emp_test.cpp"*/

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
