#include <iostream>

void dirtyStack() {
    // We create some variables and give them values
    int a = 42;
    int b = 24;
    int c = 66;
    // These values are now sitting on the stack memory
    std::cout << "Dirtying stack with: " << a << ", " << b << ", " << c << "\n";
}

void seeTheJunk() {
    int x; // Uninitialized!
    // x will likely land on the same memory address where a, b, or c just were
    std::cout << "Value of uninitialized x: " << x << "\n";
}

int main() {
    dirtyStack();
    seeTheJunk();
    return 0;
}