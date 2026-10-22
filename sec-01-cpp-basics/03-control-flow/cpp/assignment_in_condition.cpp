#include <iostream>

int main() {
    int x{5};

    if (x = 0) { // oops: = assigns, == compares
        std::cout << "x is zero\n";
    } else {
        std::cout << "x is not zero\n";
    }
    std::cout << "x is now " << x << '\n';
    return 0;
}
