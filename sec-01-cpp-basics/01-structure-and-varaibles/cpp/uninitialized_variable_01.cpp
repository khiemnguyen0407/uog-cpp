#include <iostream>

int main() {
    int x;                  // uninitialized: no value given
    std::cout << x << '\n'; // who knows what we get?

    int y{}; // value-initialized to 0
    std::cout << y << '\n';

    int z{42}; // initialized to 42
    std::cout << z << '\n';
    return 0;
}
