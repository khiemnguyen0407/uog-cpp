#include <iostream>

int main() {
    int x{5};
    std::cout << x << '\n';  // the value of x
    std::cout << &x << '\n'; // the address of x

    double d{42.0};
    std::cout << &d << '\n'; // the address of d
    return 0;
}
