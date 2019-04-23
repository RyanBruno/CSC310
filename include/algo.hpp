#include "pch.hpp"

struct Point {
    int x;
    int y;
};

template <int I>
struct Polygon {
    std::array<Point, I> points;
};

template <int I, typename OutputIterator>
void scanline(const std::array<Point, I>& polygon,
              OutputIterator& output)
{
    unsigned int max_y = 0;
    unsigned int min_y = UINT_MAX;
    std::for_each(polygon.begin(), polygon.end(), [](const Polygon& p)
    {
        if (p.y > max_y)
        {
            max_y = p.y;
        }
        if (p.y < min_y)
        {
            min_y = p.y;
        }
    });

    for (int y = min_y; y < max_y; y++)
    {
        for (int i = 0; i < I; i++)
        {
            Point p_0 = polygon[i];
            Point p_1 = polygon[(i + 1) % I];
            Point p_2 = polygon[(i + 2) % I];

            if (p_2.y != p_1.y &&
                y >= std::min(p_1.y, p_2.y) &&
                y <= std::max(p_1.y, p_2.y))
            {
                 // x = (y - y_1) (x_2 - x_1)/(y_2 - y_1) + x_1
                float point_x = (y - p_1.y) * ((float) (p_2.x - p_1.x) / (p_2.y - p_1.y)) + p_1.x;

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
}
