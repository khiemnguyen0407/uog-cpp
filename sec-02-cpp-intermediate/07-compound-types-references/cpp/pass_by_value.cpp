#include <iostream>

void print_value(double v) { // v is a copy of x: cheap for a double
    std::cout << v << '\n';
}

int main() {
    double x{42.0};
    print_value(x);
    return 0;
}
