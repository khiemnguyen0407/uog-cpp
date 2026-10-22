#include <iostream>

template <typename T>
T max(T x, T y) {
    std::cout << "template max<T>: ";
    return (x < y) ? y : x;
}

int max(int x, int y) {
    std::cout << "ordinary max: ";
    return (x < y) ? y : x;
}

int main() {
    std::cout << max<int>(1, 2) << '\n'; // template, T = int
    std::cout << max<>(1, 2) << '\n';    // template, T deduced
    std::cout << max(1, 2) << '\n';      // ordinary wins
    return 0;
}
