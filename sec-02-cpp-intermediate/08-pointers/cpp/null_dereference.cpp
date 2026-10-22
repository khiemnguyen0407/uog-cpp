#include <iostream>

int main() {
    int* ptr{nullptr};
    std::cout << *ptr << '\n'; // undefined behaviour!
    return 0;
}
