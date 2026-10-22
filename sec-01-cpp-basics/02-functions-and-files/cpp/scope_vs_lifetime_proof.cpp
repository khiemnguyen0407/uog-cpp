#include <iostream>

void second_function(int* address_of_x) {
    // The NAME x is out of scope, but we know its ADDRESS
    std::cout << "x is at " << address_of_x << '\n';
    std::cout << "x holds " << *address_of_x << '\n';
}

void first_function() {
    int x{10};           // x is alive from here...
    second_function(&x); // &x means "the address of x"
} // ...to here

int main() {
    first_function();
    return 0;
}
