#include "pch.hpp"
#include "algo.hpp"

int main() {
    const std::array<Point, 3> polygon = {{{0,0}, {10, 10}, {10,0}}};

    auto output = scanline<3>(polygon);

    std::for_each(output.begin(), output.end(), [](const Point& result) 
    {
        std::cout << result.x << "," << result.y << std::endl;
    });
    
    return 0;
}
