#include <iostream>

template <typename T>
T add_one(T x) {
    return x + 1;
}

int main() {
    std::cout << add_one(41) << '\n';              // fine: 42
    std::cout << add_one("Hello, world!") << '\n'; // compiles... but?
    return 0;
}
