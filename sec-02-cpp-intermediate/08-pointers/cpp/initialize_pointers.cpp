#include <iostream>

int main() {
    int x{5};

    int* ptr1;     // uninitialized: holds a garbage address (wild!)
    int* ptr2{};   // a null pointer: points at nothing
    int* ptr3{&x}; // points at x

    std::cout << *ptr3 << '\n';
    return 0;
}
