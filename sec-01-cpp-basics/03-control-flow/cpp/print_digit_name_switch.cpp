#include <iostream>

void print_digit_name(int x) {
    switch (x) {
    case 1:
        std::cout << "One\n";
        return;
    case 2:
        std::cout << "Two\n";
        return;
    case 3:
        std::cout << "Three\n";
        return;
    default:
        std::cout << "Unknown\n";
        return;
    }
}

int main() {
    print_digit_name(2);
    return 0;
}
