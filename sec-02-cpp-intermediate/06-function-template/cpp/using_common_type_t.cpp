#include <iostream>
#include <type_traits> // common_type_t

template <typename T, typename U>
std::common_type_t<T, U> max(T x, U y) {
    return (x < y) ? y : x;
}

int main() {
    std::cout << max(5, 10.5) << '\n';
    return 0;
}
