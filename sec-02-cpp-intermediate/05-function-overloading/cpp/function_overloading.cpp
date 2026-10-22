#include <iostream>

int add(int x, int y) { // integer version
    return x + y;
}

double add(double x, double y) { // floating-point version
    return x + y;
}

int main() {
    std::cout << add(1, 2) << '\n';        // add(int, int)
    std::cout << add(42.25, 24.5) << '\n'; // add(double, double)
    return 0;
}
