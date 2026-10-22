#include <iostream>
#include <vector>

int main() {
    std::cout << "How many numbers? ";
    int length{};
    std::cin >> length;

    std::vector<int> numbers(length);

    for (int i{0}; i < length; ++i) {
        numbers[i] = i * i;
    }
    for (int i{0}; i < length; ++i) {
        std::cout << numbers[i] << ' ';
    }
    std::cout << '\n';
    return 0;
} // no delete[]: the vector frees its own memory here
