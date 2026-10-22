#include <iostream>

// Only a declaration of the template is left...
template <typename T>
T max(T x, T y);

// ...plus the function the compiler generated from it for T = int
template <>
int max<int>(int x, int y) {
    return (x < y) ? y : x;
}

int main() {
    std::cout << max<int>(1, 2) << '\n';
    return 0;
}
