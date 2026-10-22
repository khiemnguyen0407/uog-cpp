#include <iostream>

void add_value(double& y, double v) { // y is bound to the caller's x
    y += v;                           // so this changes x itself
}

int main() {
    double x{42.0};
    std::cout << "x = " << x << '\n';
    add_value(x, 24.0);
    std::cout << "x = " << x << '\n';
    return 0;
}
