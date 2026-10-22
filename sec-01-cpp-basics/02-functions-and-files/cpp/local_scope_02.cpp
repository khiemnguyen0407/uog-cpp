#include <iostream>

int main() {
    int a{5};

    { // a nested block starts here
        int b{10};
        std::cout << a + b << '\n'; // a and b in scope
    } // b goes out of scope (and is destroyed) here

    std::cout << b << '\n'; // error: b is not in scope
    return 0;
}
