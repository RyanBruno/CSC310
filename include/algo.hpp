#include "pch.hpp"
#include <climits>

struct Point {
    unsigned int x;
    unsigned int y;

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
        return false;
    }
};

struct Edge {
    Point p_1; // Always lower y
    Point p_2; // Always Greater y

    double cur_x; // Starts at p_1.x, moves with y
    double delta_x;

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
std::set<Point>
scanline(const RandomAccessIterator& polygon_begin, const int& len)
{
    std::set<Point> result;// TODO change
    std::vector<Edge> edge;

    for (int i = 0; i < len; i++)
    {
        Point p_1 = polygon_begin[i];
        Point p_2 = polygon_begin[(i + 1) % len];

        if (p_2.y == p_1.y)
            continue;

        if (p_2.y < p_1.y)
        {
            Point temp = p_1;
            p_1 = p_2;
            p_2 = temp;
        }

        edge.push_back(Edge());
        edge.back().p_1 = p_1;
        edge.back().p_2 = p_2;
        edge.back().delta_x = (double) (p_2.x - p_1.x) / (p_2.y - p_1.y);
        edge.back().cur_x = (double) p_1.x;
    }

    std::sort(std::begin(edge), std::end(edge));

    std::for_each(edge.begin(), edge.end(), [] (const Edge& edge)
    {
        std::cout << edge.p_1.x << "," << edge.p_1.y << "-" << edge.p_2.x << "," << edge.p_2.y << "\t" << edge.cur_x << " + " << edge.delta_x << std::endl;
    });

    int j = 0;
    int k = 0;

    std::cout << "min: " << edge.front().p_1.y << ", max: " << edge.back().p_2.y << std::endl;

    for (int y = edge[0].p_1.y; y < edge.back().p_2.y; y++)
    {
        std::cout << "j: " << j << ", k: " << k << ", y: " << y << std::endl;
        for (int i = j; i < k; i++)
        {
            
            std::cout << "Added: " << edge[i].cur_x << " to " << edge[i].delta_x << std::endl;
            edge[i].cur_x += edge[i].delta_x;
        }

        while (edge[k].p_1.y == y && k < edge.size()) {
            k++;
            std::cout << "k++" << std::endl;
        }

        // Sort [j, k) by cur_x
        std::sort(std::begin(edge) + j, std::begin(edge) + k);

        for (int i = j; i < k; i++)
        {

            // TODO Check for local min/max
            result.insert({(unsigned int) edge[i].cur_x, (unsigned int) y});
            std::cout << "helow" << std::endl;

            if (edge[i].p_2.y == y)
            {
                Edge temp = edge[i];
                edge[i] = edge[k];
                edge[k] = temp;
                j++;
            }
        }
    }
    return result;
}
