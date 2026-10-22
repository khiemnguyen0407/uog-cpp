#include <iostream>

int& larger(int& a, int& b) { // returns a reference to a or to b
    return (a > b) ? a : b;
}

int main() {
    int x{5};
    int y{8};

    larger(x, y) = 0; // resets whichever is larger: here, y
    std::cout << "x = " << x << ", y = " << y << '\n';
    return 0;
}
