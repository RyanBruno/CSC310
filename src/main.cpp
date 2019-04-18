#include "pch.hpp"
#include "algo.hpp"

int main() {
    std::array<Point, 3> polygon {{{0,0}, {1,2}, {2,0}}};
    std::array<float, 3> output;
    std::array<float, 3>::iterator output_it= output.begin();

    scanline<3>(polygon, 1, output_it);

    std::for_each(output.begin(), output_it, [](const float& result) 
    {
        std::cout << result << std::endl;
    });
    
    return 0;
}
