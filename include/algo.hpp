#include "pch.hpp"

struct Point {
    int x;
    int y;
};

template <int I>
struct Polygon {
    std::array<Point, I> points;
};

template <int I,
          typename OutputIterator>
void scanline(const std::array<Point, I>& polygon,
              const int& scan_y,
              OutputIterator& output)
{
    Point p_0 = polygon[0];
    Point p_1 = polygon[1];
    Point p_2 = polygon[2];
    for (int i = 0;
         i < I;
         i++,
         p_0 = polygon[i],
         p_1 = polygon[(i + 1) % I],
         p_2 = polygon[(i + 2) % I])
    {
        if (p_2.y != p_1.y &&
            scan_y >= std::min(p_1.y, p_2.y) &&
            scan_y <= std::max(p_1.y, p_2.y))
        {
             // x = (y - y_1) (x_2 - x_1)/(y_2 - y_1) + x_1
            float point_x = (scan_y - p_1.y) *
                            ((float) (p_2.x - p_1.x) / (p_2.y - p_1.y)) + p_1.x;
            
            if (point_x == p_1.x)
            {
                if (std::min({p_0.y, p_1.y, p_2.y}) != p_1.y &&
                    std::max({p_0.y, p_1.y, p_2.y}) != p_1.y)
                {
                    *output = point_x;
                    output++;
                }
            } else if (point_x != p_2.x) 
            {
                *output = point_x;
                output++;
            }
            
        }
    }
}
