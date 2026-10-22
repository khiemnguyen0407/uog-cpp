#include <iostream>
#include <string>

template <typename T>
T add_value(T x, double v) {
    return x + v;
}

int main() {
    std::cout << add_value(4.2, 2.4) << '\n'; // fine: double + double

    std::string hello{"Hello, world!"};
    std::cout << add_value(hello, 4.2) << '\n'; // string + double?!
    return 0;
}
