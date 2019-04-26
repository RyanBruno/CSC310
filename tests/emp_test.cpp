
TEST(TestEmp, Test310) 
{
    std::array<Point, 3> polygon;
    generate_polygon<3>(polygon, 10);

    scanline<3>(polygon);
}
