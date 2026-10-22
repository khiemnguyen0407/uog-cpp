#include <iostream>

// T: template parameter; times: an ordinary int
template <typename T>
void print_repeated(T value, int times = 1) {
    for (int i{0}; i < times; ++i) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}

int main() {
    print_repeated(5);      // T = int, times = 1
    print_repeated('a', 3); // T = char, times = 3
    print_repeated(2.5, 2); // T = double, times = 2
    return 0;
}
