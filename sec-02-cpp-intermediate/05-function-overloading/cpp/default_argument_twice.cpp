#include <iostream>

void print(int x, int y = 4); // forward declaration with default

void print(int x, int y = 4) { // error: default given again
    std::cout << "x: " << x << ", y: " << y << '\n';
}

int main() {
    print(3);
    return 0;
}
