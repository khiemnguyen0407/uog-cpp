#include <iostream>

int main() {
    int* ptr{new int}; // an int on the heap
    *ptr = 7;          // use it through the pointer
    std::cout << *ptr << '\n';

    int* ptr2{new int{6}}; // allocate AND initialize
    std::cout << *ptr2 << '\n';

    delete ptr; // give the memory back
    delete ptr2;
    return 0;
}
