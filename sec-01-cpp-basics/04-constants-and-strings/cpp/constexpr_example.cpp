#include <iostream>
#include <numbers> // C++20: std::numbers::pi

int main() {
    constexpr double pi{std::numbers::pi}; // compile time

    std::cout << "Radius: ";
    double radius{};
    std::cin >> radius;

    const double area{pi * radius * radius}; // run time
    std::cout << "Area: " << area << '\n';
    return 0;
}
