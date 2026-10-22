#include <iostream>

void print_value(const int& y) { // a const reference
    std::cout << y << '\n';
}

int main() {
    int x{5};
    print_value(x); // fine: a modifiable lvalue

    const int z{6};
    print_value(z); // fine: a const lvalue

    print_value(7); // fine: an rvalue (bound to a temporary)
    return 0;
}
