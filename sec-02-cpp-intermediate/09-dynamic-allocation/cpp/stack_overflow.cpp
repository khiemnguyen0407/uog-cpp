#include <iostream>

int main() {
    int numbers[10'000'000]; // 10 million ints (40 MB) on the stack
    numbers[0] = 1;
    std::cout << numbers[0] << '\n';
    return 0;
}
