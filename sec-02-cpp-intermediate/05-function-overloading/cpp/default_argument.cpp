#include <iostream>

void print(int x, int y = 4) { // 4 is the default argument
    std::cout << "x: " << x << ", y: " << y << '\n';
}

int main() {
    print(1, 2); // y uses the argument we give: 2
    print(3);    // y uses the default: same as print(3, 4)
    return 0;
}
