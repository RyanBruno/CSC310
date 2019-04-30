#include "pch.hpp"
#include "algo.hpp"
#include <vector>


int main(int argc, const char* argv[])
{
    std::string input;
    std::vector<Point> points;

    std::cout << "Enter points:" << std::endl;

    while (true)
    {
        std::getline(std::cin, input);

        if (input.empty())
        {
            break;
        }

        auto pos = input.find(" ");

        if (pos == std::string::npos)
        {
            std::cout << "Error: input must be in form int<space>int\\n" << std::endl;
            return 1;
        }

        points.emplace_back(Point());
        points.back().x = std::stoi(input);
        points.back().y = std::stoi(input.substr(pos));
    }

    auto results = scanline(points.begin(), points.size());

    std::for_each(results.begin(), results.end(), [] (const Point& p)
    {
        std::cout << p.x << "," << p.y << std::endl;
    });
}
