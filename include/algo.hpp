#include "pch.hpp"
#include <climits>

struct Point {
    int x;
    int y;

    bool min_or_max;

    bool operator< (const Point& other) const
    {
        if (y == other.y)
        {
            return x < other.x;
        }
        return y < other.y;
    }

    bool operator== (const Point& other) const
    {
        return x == other.x && y == other.y;
    }
};

struct Edge {
    Point p_1; // Always lower y
    Point p_2; // Always Greater y

    float cur_x; // Starts at p_1.x, moves with y
    float delta_x;

    bool operator< (const Edge& other) const
    {
        if (p_1.y == other.p_1.y)
        {
            return cur_x < other.cur_x;
        }
        return p_1.y < other.p_1.y;
    }
};


template <int I>
struct Polygon {
    std::array<Point, I> points;
};

template <typename RandomAccessIterator>
std::vector<Point>
scanline(const RandomAccessIterator& polygon_begin, const int& len)
{
    std::vector<Point> result;
    std::vector<Edge> edge;
    int max_y = 0;

    for (int i = 0; i < len; i++)
    {
        Point p_0 = polygon_begin[i];
        Point p_1 = polygon_begin[(i + 1) % len];
        Point p_2 = polygon_begin[(i + 2) % len];

        if (p_2.y == p_1.y)
            continue;

        p_1.min_or_max = std::min({p_0.y, p_1.y, p_2.y}) == p_1.y ||
                         std::max({p_0.y, p_1.y, p_2.y}) == p_1.y;
        if (p_2.y < p_1.y)
        {
            Point temp = p_1;
            p_1 = p_2;
            p_2 = temp;
        }

        if (p_2.y > max_y)
            max_y = p_2.y;

        edge.push_back(Edge());
        edge.back().p_1 = p_1;
        edge.back().p_2 = p_2;
        edge.back().delta_x = (float) (p_2.x - p_1.x) / (p_2.y - p_1.y);
        edge.back().cur_x = (float) p_1.x;
    }

    std::sort(std::begin(edge), std::end(edge));

    int j = 0;
    int k = 0;

    for (int y = edge[0].p_1.y; y < max_y; y++)
    {
        for (int i = j; i < k; i++)
            edge[i].cur_x += edge[i].delta_x;

        while (edge[k].p_1.y == y && k < edge.size())
            k++;

        // Sort [j, k) by cur_x
        std::sort(std::begin(edge) + j, std::begin(edge) + k, [](const Edge& e_1, const Edge& e_2)
        {
            return e_1.cur_x < e_2.cur_x;
        });

        for (int i = j; i < k; i++)
        {
            if (edge[i].p_1.y != y &&
               (edge[i].p_2.y != y || !edge[i].p_2.min_or_max))
            {
                result.push_back(Point());
                result.back().x = (int) edge[i].cur_x;
                result.back().y = (int) y;
            }

            if (edge[i].p_2.y == y)
            {
                Edge temp = edge[i];
                edge[i] = edge[j];
                edge[j] = temp;
                j++;
            }
        }
    }
    return result;
}
