#include <iostream>

int main() {
    int* ptr{nullptr};
    {
        int x{5};
        ptr = &x;
    } // x is destroyed here: ptr now dangles

    std::cout << *ptr << '\n'; // undefined behaviour!
    return 0;
}
