#include <iostream>

auto max(auto x, auto y) { // C++20: a template without the template line
    return (x < y) ? y : x;
}

int main() {
    std::cout << max(2, 3.5) << '\n';   // int and double
    std::cout << max('a', 'z') << '\n'; // char and char
    return 0;
}
