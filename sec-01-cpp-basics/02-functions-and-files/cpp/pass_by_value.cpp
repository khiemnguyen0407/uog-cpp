#include <iostream>

void try_to_swap(int x, int y) {
    int temp{x};
    x = y;
    y = temp;
    std::cout << "In try_to_swap(): " << x << ' ' << y << '\n';
}

int main() {
    int x{100};
    int y{200};
    try_to_swap(x, y);
    std::cout << "Back in main():   " << x << ' ' << y << '\n';
    return 0;
}
