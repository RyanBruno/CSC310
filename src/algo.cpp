#include "algo.hpp"
#include <iterator>

template <typename InputIterator>
std::vector<Point>
scanline(const InputIterator& polygon_begin,
         const InputIterator& polygon_end,
         const int& scan_y)
{
    // Loop through for edges
    // If a edge has an intercection with scan line add to list
    // Check for local max/min
    // Return list
}

int add(int a, int b) {
    return a + b;
}
