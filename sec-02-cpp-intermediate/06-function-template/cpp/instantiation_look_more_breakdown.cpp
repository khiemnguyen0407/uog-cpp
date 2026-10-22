#include <iostream>

template <typename T>
T max(T x, T y); // only the declaration is left

template <>
int max<int>(int x, int y) { // generated for T = int
    return (x < y) ? y : x;
}

template <>
double max<double>(double x, double y) { // generated for T = double
    return (x < y) ? y : x;
}

int main() {
    std::cout << max<int>(1, 2) << '\n';
    std::cout << max<int>(4, 3) << '\n';
    std::cout << max<double>(1, 2) << '\n';
    return 0;
}
