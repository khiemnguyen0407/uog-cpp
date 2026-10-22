#include <iostream>

void print_value(const int* ptr) { // receives an address
    if (ptr == nullptr) {
        std::cout << "(no object)\n";
        return;
    }
    std::cout << *ptr << '\n';
}

int main() {
    int x{42};
    print_value(&x);      // pass the address of x
    print_value(nullptr); // "no object" is a valid argument
    return 0;
}
