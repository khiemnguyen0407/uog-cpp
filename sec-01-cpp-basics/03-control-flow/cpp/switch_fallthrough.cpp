#include <iostream>

int main() {
    int x{2};

    switch (x) {
    case 1:
        std::cout << "One\n";
    case 2:
        std::cout << "Two\n"; // x matches here...
    case 3:
        std::cout << "Three\n"; // ...but this runs too
    default:
        std::cout << "Unknown\n"; // ...and so does this!
    }
    return 0;
}
