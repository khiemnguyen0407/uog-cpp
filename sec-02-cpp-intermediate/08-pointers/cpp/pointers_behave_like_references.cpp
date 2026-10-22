#include <iostream>

int main() {
    int x{5};
    int& ref{x};  // a reference to x
    int* ptr{&x}; // a pointer to x

    std::cout << x << ' ' << ref << ' ' << *ptr << '\n';

    ref = 6; // change x through the reference
    std::cout << x << ' ' << ref << ' ' << *ptr << '\n';

    *ptr = 7; // change x through the pointer
    std::cout << x << ' ' << ref << ' ' << *ptr << '\n';
    return 0;
}
