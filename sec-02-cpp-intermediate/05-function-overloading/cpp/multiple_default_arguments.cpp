#include <iostream>

void print_numbers(int x = 10, int y = 20, int z = 30) {
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

int main() {
    print_numbers(1, 2, 3); // no defaults used
    print_numbers(1, 2);    // z defaulted
    print_numbers(1);       // y and z defaulted
    print_numbers();        // all three defaulted
    return 0;
}
