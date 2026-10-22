#include <iostream>

template <typename T>
T max(T x, T y) {
    return (x < y) ? y : x;
}

int main() {
    std::cout << max<double>(2, 3.5) << '\n'; // T = double: 2 becomes 2.0
    return 0;
}
