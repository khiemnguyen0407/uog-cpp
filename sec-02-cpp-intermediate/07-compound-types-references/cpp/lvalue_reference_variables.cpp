#include <iostream>

int main() {
    int x{5};    // an ordinary int variable
    int& ref{x}; // ref is a reference to x: another name for x

    std::cout << x << '\n';   // prints 5
    std::cout << ref << '\n'; // prints 5, through ref
    return 0;
}
