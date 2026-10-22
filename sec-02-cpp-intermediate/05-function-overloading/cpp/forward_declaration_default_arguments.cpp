#include <iostream>

void print(int x, int y = 4); // the default goes here...

int main() {
    print(3);
    return 0;
}

void print(int x, int y) { // ...and not here
    std::cout << "x: " << x << ", y: " << y << '\n';
}
