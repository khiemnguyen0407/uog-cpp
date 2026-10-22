#include <iostream>

int main() {
    int* ptr{new int{42}};
    std::cout << *ptr << '\n';

    delete ptr;    // the int is gone, but ptr still holds its address
    ptr = nullptr; // so say so: "nothing allocated"

    delete ptr; // deleting a null pointer is safe: it does nothing

    if (!ptr) {           // nothing allocated yet?
        ptr = new int{7}; // then allocate
    }
    std::cout << *ptr << '\n';
    delete ptr;
    return 0;
}
