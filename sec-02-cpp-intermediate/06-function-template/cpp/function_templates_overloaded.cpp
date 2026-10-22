#include <iostream>

template <typename T>
auto add(T x, T y) { // same types
    return x + y;
}

template <typename T, typename U>
auto add(T x, U y) { // different types
    return x + y;
}

template <typename T, typename U, typename V>
auto add(T x, U y, V z) { // three values
    return x + y + z;
}

int main() {
    std::cout << add(1.2, 3.4) << '\n'; // add<double>
    std::cout << add(5.6, 7) << '\n';   // add<double, int>
    std::cout << add(8, 9, 10) << '\n'; // add<int, int, int>
    return 0;
}
