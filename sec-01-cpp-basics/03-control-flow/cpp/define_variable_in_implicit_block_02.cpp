#include <iostream>

int main() {
    if (true) {
        int x{5};
    } // this x is destroyed here
    else {
        int x{6};
    } // and this x is destroyed here

    std::cout << x << '\n'; // no x is in scope here
    return 0;
}
