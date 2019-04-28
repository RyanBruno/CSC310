template <int I>
void generate_polygon(
        std::array<Point, I>& polygon, const int& n)
{
    std::srand(std::time(nullptr));
    polygon[0] = {0,0};
    polygon[1] = {0,n};

    std::for_each(polygon.begin() + 2, polygon.end(), [&n](Point& p)
    {
        p.x = std::rand() % 1000;
        p.y = std::rand() % n;
    });
}

TEST(TestEmp, Test310) 
{
    std::array<Point, 3> polygon;
    generate_polygon<3>(polygon, 10);

    scanline<3>(polygon);
}
