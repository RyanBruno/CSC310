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

template <int I>
std::set<Point, point_cmp>
scanline(const std::array<Point, I>& polygon)
{
    std::set<Point, point_cmp> result;

    auto min_max = std::minmax_element(polygon.begin(), polygon.end(), point_compare);

    for (int y = min_max.first->y; y < min_max.second->y; y++)
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
