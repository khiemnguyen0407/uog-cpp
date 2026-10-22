#include <iostream>

const double get_value() { // const here does nothing
    return 42.0;
}

int main() {
    std::cout << get_value() << '\n';
    return 0;
}
