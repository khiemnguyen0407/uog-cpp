#include <iostream>

template <typename T>
struct Pair {
    T first{};
    T second{};
};

template <typename T>
constexpr T max(Pair<T> p) { // a function template taking a Pair<T>
    return (p.first < p.second) ? p.second : p.first;
}

int main() {
    Pair<int> p1{5, 6};
    std::cout << max<int>(p1) << " is larger\n"; // T given explicitly

    Pair<double> p2{1.2, 3.4};
    std::cout << max(p2) << " is larger\n"; // T deduced (prefer this)
    return 0;
}
