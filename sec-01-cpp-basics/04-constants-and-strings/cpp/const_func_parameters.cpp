#include <iostream>

void print_double(const int x) { // x is read-only
    std::cout << x * 2 << '\n';
}

int main() {
    print_double(21);
    return 0;
}
