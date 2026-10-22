#include <iostream>

int add(int x, int y) { return x + y; }

int multiply(int x, int y) { return x * y; }

int main() {
    std::cout << add(4, 5) << '\n';         // x = 4, y = 5
    std::cout << add(1 + 2, 3 * 4) << '\n'; // x = 3, y = 12

    int a{5};
    std::cout << add(a, a) << '\n'; // x = 5, y = 5

    std::cout << add(1, multiply(2, 3)) << '\n'; // 1 + (2 * 3)
    std::cout << add(1, add(2, 3)) << '\n';      // 1 + (2 + 3)
    return 0;
}
