#include <iostream>

int main() {
    // Print the numbers below 50 that are even AND multiples of 3
    for (int n{1}; n < 50; ++n) {
        if (n % 2 == 0) {
            if (n % 3 == 0) {
                std::cout << n << ' '; // the real work, two levels deep
            }
        }
    }
    std::cout << '\n';
    return 0;
}
