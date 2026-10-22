#include <iostream>

int main() {
    int x{42};

    {                             // a nested block
        int& ref{x};              // ref is a reference to x
        std::cout << ref << '\n'; // prints 42
    } // ref is destroyed here; x doesn't notice

    std::cout << x << '\n'; // still prints 42
    return 0;
} // x is destroyed here
