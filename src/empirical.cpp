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
void time_algo(int n)
{
    std::array<Point, M> data;
    generate_polygon<M>(data, n);
    auto start = std::chrono::steady_clock::now();

    scanline(data.begin(), M);

	auto end = std::chrono::steady_clock::now();
    std::cout << M << "\t" << n << "\t" << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
}

int main() {

    std::cout << "M\tN\tns" << std::endl;

    /* time_algo<M>(n) */
    time_algo<10>(10);
    time_algo<10>(50);
    time_algo<10>(100);
    time_algo<10>(500);
    time_algo<10>(1000);
    time_algo<10>(1500);

    time_algo<50>(10);
    time_algo<50>(50);
    time_algo<50>(100);
    time_algo<50>(500);
    time_algo<50>(1000);
    time_algo<50>(1500);

    time_algo<100>(10);
    time_algo<100>(50);
    time_algo<100>(100);
    time_algo<100>(500);
    time_algo<100>(1000);
    time_algo<100>(1500);

    time_algo<500>(10);
    time_algo<500>(50);
    time_algo<500>(100);
    time_algo<500>(500);
    time_algo<500>(1000);
    time_algo<500>(1500);

    time_algo<1000>(10);
    time_algo<1000>(50);
    time_algo<1000>(100);
    time_algo<1000>(500);
    time_algo<1000>(1000);
    time_algo<1000>(1500);

    time_algo<1500>(10);
    time_algo<1500>(50);
    time_algo<1500>(100);
    time_algo<1500>(500);
    time_algo<1500>(1000);
    time_algo<1500>(1500);


    return 0;
}

