#include "pch.hpp"
#include "algo.hpp"
#include <ctime>
template <int I>
void generate_polygon(
        std::array<Point, I>& polygon, const int& n);

int main() {
    const std::array<Point, 3> polygon = {{{0,0}, {10, 10}, {10,0}}};

    auto output = scanline<3>(polygon.begin());

    std::for_each(output.begin(), output.end(), [](const Point& result) 
    {
        std::cout << result.x << "," << result.y << std::endl;
    });

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::array<Point, 10000> polygon2;

    generate_polygon<10000>(polygon2, 10000);

std::for_each(polygon2.begin(), polygon2.end(), [](const Point& result) 
    {
        //std::cout << result.x << "," << result.y << std::endl;
    });

std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    
    auto initial = std::time(nullptr);
    auto output2 = scanline<10000>(polygon2.begin());
    auto time = std::time(nullptr) - initial;
    std::cout << time << std::endl;



    std::for_each(output2.begin(), output2.end(), [](const Point& result) 
    {
        std::cout << result.x << "," << result.y << std::endl;
    });


    
    return 0;
}

template <int I>
void generate_polygon(
        std::array<Point, I>& polygon, const int& n)
{
    std::srand(std::time(nullptr));
    polygon[0] = {0,0};
    polygon[1] = {0,n};
    std::for_each(polygon.begin() + 2, polygon.end(), [&](Point& p)
    {
        p.x = std::rand() % 1000;
        p.y = std::rand() % n;
        std::cout << "De " << p.x << "," << p.y << std::endl;
    });
}
