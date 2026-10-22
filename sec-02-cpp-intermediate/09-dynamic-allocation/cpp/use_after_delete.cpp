#include <iostream>

int main() {
    int* ptr{new int{7}};
    delete ptr; // ptr is now dangling

    std::cout << *ptr << '\n'; // undefined behaviour: use after delete
    delete ptr;                // undefined behaviour: delete twice
    return 0;
}
