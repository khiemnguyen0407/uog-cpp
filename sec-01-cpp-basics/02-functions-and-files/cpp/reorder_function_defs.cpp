#include <iostream>

int add(int x, int y) { // defined first...
    return x + y;
}

int main() {
    std::cout << "3 + 4 = " << add(3, 4) << '\n'; // ...used after
    return 0;
}
