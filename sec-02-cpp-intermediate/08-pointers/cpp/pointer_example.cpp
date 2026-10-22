#include <iostream>

int main() {
    int x{425};
    int* ptr{&x}; // ptr is a pointer to int, holding the address of x

    std::cout << "x lives at:   " << &x << '\n';
    std::cout << "ptr holds:    " << ptr << '\n';
    std::cout << "*ptr gives:   " << *ptr << '\n';
    std::cout << "ptr lives at: " << &ptr << '\n'; // a pointer is an object
    return 0;
}
