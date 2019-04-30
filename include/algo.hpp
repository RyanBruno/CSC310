#include "pch.hpp"
#include <climits>

struct Point {
    int x;
    int y;

   bool operator== (const Point& other) const
   {
       return x == other.x && y == other.y;
   }
};

template <int I>
struct Polygon {
    std::array<Point, I> points;
};

bool point_compare (const Point& p_1, const Point& p_2) {
    if (p_1.y == p_2.y)
    {
        return p_1.x < p_2.x;
    }
    return p_1.y < p_2.y;
}

struct point_cmp {
    bool operator() (const Point& p_1, const Point& p_2) {
        return point_compare(p_1, p_2);
    }
};

template <typename RandomAccessIterator>
std::set<Point, point_cmp>
scanline(const RandomAccessIterator& polygon_begin, const int& len)
{
    std::set<Point, point_cmp> result;

    auto min_max = std::minmax_element(polygon_begin, polygon_begin + len, point_compare);

    for (int y = min_max.first->y; y < min_max.second->y; y++)
    {
        for (RandomAccessIterator i = polygon_begin;
             i != polygon_begin + len; i++)
        {
            Point p_0 = *i;
            Point p_1 = *(polygon_begin + ((i - polygon_begin + 1) % len));
            Point p_2 = *(polygon_begin + ((i - polygon_begin + 2) % len));

            if (p_2.y != p_1.y &&
                y >= std::min(p_1.y, p_2.y) &&
                y <= std::max(p_1.y, p_2.y))
            {
                 // x = (y - y_1) (x_2 - x_1)/(y_2 - y_1) + x_1
                int point_x = (int) ((y - p_1.y) * ((float) (p_2.x - p_1.x) / (p_2.y - p_1.y)) + p_1.x);

                if (point_x == p_1.x && y == p_1.y)
                {
                    if (std::min({p_0.y, p_1.y, p_2.y}) != p_1.y &&
                        std::max({p_0.y, p_1.y, p_2.y}) != p_1.y)
                    {
                        result.insert({point_x, y});
                    }
                } else if (point_x != p_2.x || y != p_2.y)
                {
                    result.insert({point_x, y});
                }
            }
        }
    }
    return result;
}
