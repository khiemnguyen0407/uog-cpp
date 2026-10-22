#include <iostream>

int main() {
    double x{42.0};
    double y{24.0};
    double* ptr{&x}; // ptr points at x

    *ptr = 10.0; // changes x: x becomes 10
    std::cout << "x = " << x << '\n';

    ptr = &y;    // change what ptr points at: now y
    *ptr = 12.0; // so this changes y
    std::cout << "y = " << y << '\n';
    return 0;
}
