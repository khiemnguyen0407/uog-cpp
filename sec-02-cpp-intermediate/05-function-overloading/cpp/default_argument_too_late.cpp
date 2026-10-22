#include <iostream>

void print(int x, int y); // forward declaration: no default here

int main() {
    print(3); // error: the compiler doesn't know about the default yet
    return 0;
}

void print(int x, int y = 4) {
    std::cout << "x: " << x << ", y: " << y << '\n';
}
