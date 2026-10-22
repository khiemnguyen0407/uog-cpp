#include <iostream>

void print_addresses(double val, double& ref) {
    std::cout << "address of val (a copy):  " << &val << '\n';
    std::cout << "address of ref (no copy): " << &ref << '\n';
}

int main() {
    double x{42.0};
    std::cout << "address of x:             " << &x << '\n';
    print_addresses(x, x);
    return 0;
}
