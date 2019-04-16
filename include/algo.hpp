struct Point {
    int x;
    int y;
}

template <int I>
struct Polygon {
    std::array<Point, I> points;
}

int add(int a, int b);
