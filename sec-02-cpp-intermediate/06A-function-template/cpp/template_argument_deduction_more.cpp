#include <iostream>
template <typename T>
T max(T x, T y) {
    std::cout << "called max<int>(int, int)\n"; return (x < y) ? y : x;
}
int max(int x, int y) {
    std::cout << "called max(int, int)\n"; return (x < y) ? y : x;
}
int main() {
    std::cout << max<int>(1, 2) << '\n'; // calls max<int>(int, int)
    // deduces max<int>(int, int) (non-template functions not considered)
    std::cout << max<>(1, 2) << '\n';    
    std::cout << max(1, 2) << '\n';      // calls max(int, int)
    return 0;
}