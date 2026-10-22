#include <iostream>

template <typename T, typename U> // two type template parameters
T max(T x, U y) {                 // x has type T, y has type U
    return (x < y) ? y : x;       // the result is converted to T!
}

int main() {
    std::cout << max(2, 3.5) << '\n'; // T = int, U = double
    return 0;
}
