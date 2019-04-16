#include <iostream>
#include <array>
#include "algo.hpp"

int main() {
    std::array<Point, 3> polygon;
    polygon[0] = Point{0,0};
    polygon[1] = Point{1,2};
    polygon[2] = Point{2,0};

    scanline(polygon.begin(), polygon.end(), 1);
    
    return 0;
}
