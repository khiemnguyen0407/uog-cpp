#include <iostream>

void swap_values(int& x, int& y) { // no copies
    int temp{x};
    x = y;
    y = temp;
}

int main() {
    int x{100};
    int y{200};
    swap_values(x, y);
    std::cout << "x = " << x << ", y = " << y << '\n';
    return 0;
}
