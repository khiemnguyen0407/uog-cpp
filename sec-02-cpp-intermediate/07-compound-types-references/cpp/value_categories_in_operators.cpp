#include <iostream>

int main() {
    std::cout << 1 + 2 << '\n'; // 1 and 2 are rvalues; so is the result

    double x{24.1};
    double y{42.2};
    std::cout << x + y << '\n'; // x and y are lvalues, converted to rvalues
    return 0;
}
