#include "pch.hpp"

struct Point {
    int x;
    int y;
};

template <int I>
struct Polygon {
    std::array<Point, I> points;
};

template <typename InputIterator, typename OutputIterator>
void
scanline(InputIterator& polygon_begin,
         const InputIterator& polygon_end,
         const int& scan_y,
         OutputIterator& output)
{
    std::optional<Point> p_0;
    Point p_1 = *polygon_begin;
    Point p_2;

    Point first = p_1;
    Point second;

    for (;
         polygon_begin != polygon_end;
         p_0 = p_1,
         p_1 = p_2)
    {
        polygon_begin++;
        if (polygon_begin == polygon_end) 
        {
            p_2 = first;
            if (std::min({p_1.y, first.y, second.y}) != first.y &&
                std::max({p_1.y, first.y, second.y}) != first.y)
            {
               *output = first.x; 
               output++;
            }
        } else {
            p_2 = *polygon_begin;
        }

        if (scan_y >= std::min(p_1.y, p_2.y) 
            && scan_y <= std::max(p_1.y, p_2.y))
        {
            /* 
             * x = (y - y_1) (x_2 - x_1)/(y_2 - x_1) + x_1
             */
            float point_x = (scan_y - p_1.y) *
                            ((float)(p_2.x - p_1.x) / (p_2.y - p_1.y)) + p_1.x;
            
                        }
            if (point_x == p_1.x) {
                if (!p_0.has_value())
                {
                    second = p_2;
                } else 
                {
                    if (std::min({p_1.y, first.y, second.y}) != first.y &&
                        std::max({p_1.y, first.y, second.y}) != first.y)
                    {
                        *output = point_x;
                        output++;
                    }
                }
            } else if (point_x != p_2.x) 
            {
                *output = point_x;
                output++;
            }
            
        }
    }
}
