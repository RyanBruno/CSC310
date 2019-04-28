
TEST(TestAlgo, TestMaxMin) 
{
    const std::array<Point, 4> polygon = {{{0,0}, {0, 10}, {10,10}, {10, 0}}};
    auto result = scanline<4>(polygon);

    ASSERT_EQ(result.size() / 2, 9);
}

TEST(TestAlgo, TestPointX)
{
    const std::array<Point, 3> polygon = {{{0,0}, {5, 5}, {5,0}}};
    auto result = scanline<3>(polygon);

    ASSERT_EQ(result.size(), 8);

    std::set<Point, point_cmp> correct = {{{1,1},{5,1},{2,2},{5,2},{3,3},{5,3},{4,4},{5,4}}};

    auto mismatch = std::mismatch(result.begin(), result.end(), correct.begin());

    ASSERT_TRUE(mismatch.first == result.end());

    ASSERT_TRUE(mismatch.second == correct.end());
}

TEST(TestAlgo, TestLocalMinMax)
{
    const std::array<Point, 5> polygon = {{{0,0}, {0, 4}, {2,2}, {4,4}, {4,0}}};
    auto result = scanline<5>(polygon);


    ASSERT_EQ(result.size(), 8);

    std::set<Point, point_cmp> correct = {{{0,1},{4,1},{0,2},{4,2},{0,3},{1,3},{3,3},{4,3}}};

    auto mismatch = std::mismatch(result.begin(), result.end(), correct.begin());

    ASSERT_TRUE(mismatch.first == result.end());

    ASSERT_TRUE(mismatch.second == correct.end());
}

TEST(TestAlgo, TestLocalNotMinMax)
{
    const std::array<Point, 5> polygon = {{{0,0}, {0, 4}, {3,4}, {1,2}, {3,0}}};
    auto result = scanline<5>(polygon);


    ASSERT_EQ(result.size(), 6);

    std::set<Point, point_cmp> correct = {{{0,1},{2,1},{0,2},{1,2},{0,3},{2,3}}};

    auto mismatch = std::mismatch(result.begin(), result.end(), correct.begin());

    ASSERT_TRUE(mismatch.first == result.end());

    ASSERT_TRUE(mismatch.second == correct.end());
}

