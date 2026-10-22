#include <iostream>

void print_value(int& y) { // only accepts modifiable lvalues
    std::cout << y << '\n';
}

int main() {
    int x{5};
    print_value(x); // fine: x is a modifiable lvalue

    const int z{5};
    print_value(z); // error: z is const
    print_value(5); // error: 5 is an rvalue
    return 0;
}
