#include <iterator>
#include <array>
#include <iostream>
struct Point {
    int x;
    int y;
};

template <int I>
struct Polygon {
    std::array<Point, I> points;
};

template <typename InputIterator>
//std::vector<Point>
auto
scanline(const InputIterator& polygon_begin,
         const InputIterator& polygon_end,
         const int& scan_y)
{
    InputIterator curr;
    InputIterator prev;
    for (prev = polygon_begin, curr = prev++;
         prev != polygon_end;
         prev++, curr++)
    {
        if (curr == polygon_end) curr = polygon_begin;
        if (scan_y >= std::min(prev->y, curr->y) 
            && scan_y <= std::max(prev->y, curr->y))
        {
            std::cout << "Found a point" << std::endl;
        }
    }
    // Check for local max/min
    // Return list
}
