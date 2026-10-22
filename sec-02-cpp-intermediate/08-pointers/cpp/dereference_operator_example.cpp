#include <iostream>

int main() {
    double x{5.0};
    std::cout << x << '\n';     // the value of x
    std::cout << &x << '\n';    // the address of x
    std::cout << *(&x) << '\n'; // the value AT that address
    return 0;
}
