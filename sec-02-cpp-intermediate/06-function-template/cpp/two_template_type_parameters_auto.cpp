#include <iostream>

template <typename T, typename U>
auto max(T x, U y) { // let the compiler work out the return type
    return (x < y) ? y : x;
}

int main() {
    std::cout << max(2, 3.5) << '\n';
    return 0;
}
