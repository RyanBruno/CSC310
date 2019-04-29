#include "pch.hpp"
#include "algo.hpp"
#include <chrono>

template <int I>
void generate_polygon(
        std::array<Point, I>& polygon, const int& n)
{
    std::srand(std::time(nullptr));
    polygon[0] = {0,0};
    polygon[1] = {0,n};

    std::for_each(polygon.begin() + 2, polygon.end(), [&n](Point& p)
    {
        p.x = std::rand() % 1000;
        p.y = std::rand() % n;
    });
}

template <int M>
void time_algo(std::array<Point, 1500> data, int n)
{
    data[1].y = n;
    auto start = std::chrono::steady_clock::now();

    scanline<M>(data.begin());

	auto end = std::chrono::steady_clock::now();
    std::cout << M << "\t" << n << "\t" << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
}

int main() {
    std::array<Point, 1500> data;
    generate_polygon<1500>(data, 10);

    std::cout << "M\tN\tns" << std::endl;

    /* time_algo<M>(data, N) */
    time_algo<10>(data, 10);
    time_algo<10>(data, 50);
    time_algo<10>(data, 100);
    time_algo<10>(data, 500);
    time_algo<10>(data, 1000);
    time_algo<10>(data, 1500);

    time_algo<50>(data, 10);
    time_algo<50>(data, 50);
    time_algo<50>(data, 100);
    time_algo<50>(data, 500);
    time_algo<50>(data, 1000);
    time_algo<50>(data, 1500);

    time_algo<100>(data, 10);
    time_algo<100>(data, 50);
    time_algo<100>(data, 100);
    time_algo<100>(data, 500);
    time_algo<100>(data, 1000);
    time_algo<100>(data, 1500);

    time_algo<500>(data, 10);
    time_algo<500>(data, 50);
    time_algo<500>(data, 100);
    time_algo<500>(data, 500);
    time_algo<500>(data, 1000);
    time_algo<500>(data, 1500);

    time_algo<1000>(data, 10);
    time_algo<1000>(data, 50);
    time_algo<1000>(data, 100);
    time_algo<1000>(data, 500);
    time_algo<1000>(data, 1000);
    time_algo<1000>(data, 1500);

    time_algo<1500>(data, 10);
    time_algo<1500>(data, 50);
    time_algo<1500>(data, 100);
    time_algo<1500>(data, 500);
    time_algo<1500>(data, 1000);
    time_algo<1500>(data, 1500);


    return 0;
}

