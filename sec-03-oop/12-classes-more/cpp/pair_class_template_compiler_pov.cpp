#include <iostream>

template <typename T>
struct Pair; // only the declaration is left

template <> // what the compiler generates for T = int...
struct Pair<int> {
    int first{};
    int second{};
};

template <> // ...and for T = double
struct Pair<double> {
    double first{};
    double second{};
};

int main() {
    Pair<int> p1{5, 6};
    std::cout << p1.first << ' ' << p1.second << '\n';
    Pair<double> p2{1.2, 3.4};
    std::cout << p2.first << ' ' << p2.second << '\n';
    return 0;
}
