#include <iostream>

void print_int(int x) { std::cout << x << '\n'; }

int main() {
    print_int(5);    // prints 5
    print_int('a');  // prints 97: does this make sense?
    print_int(true); // prints 1: does this make sense?
    return 0;
}
