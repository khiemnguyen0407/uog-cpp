#include <iostream>

int main() {
    int* ptr{nullptr}; // a null pointer: points at nothing

    if (ptr == nullptr) { // check before dereferencing!
        std::cout << "ptr is null\n";
    }

    int x{5};
    ptr = &x;
    if (ptr) { // a non-null pointer counts as true
        std::cout << "ptr points at " << *ptr << '\n';
    }
    return 0;
}
