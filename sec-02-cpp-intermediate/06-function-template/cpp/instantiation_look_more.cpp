#include <iostream>

template <typename T>
T max(T x, T y) {
    return (x < y) ? y : x;
}

int main() {
    std::cout << max<int>(1, 2) << '\n';    // instantiates max<int>
    std::cout << max<int>(4, 3) << '\n';    // reuses max<int>
    std::cout << max<double>(1, 2) << '\n'; // instantiates max<double>
    return 0;
}
