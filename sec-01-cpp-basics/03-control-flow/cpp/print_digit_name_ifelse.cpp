#include <iostream>

void print_digit_name(int x) {
    if (x == 1) {
        std::cout << "One\n";
    } else if (x == 2) {
        std::cout << "Two\n";
    } else if (x == 3) {
        std::cout << "Three\n";
    } else {
        std::cout << "Unknown\n";
    }
}

int main() {
    print_digit_name(2);
    return 0;
}
