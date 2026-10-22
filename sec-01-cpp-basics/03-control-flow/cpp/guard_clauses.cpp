#include <iostream>

int main() {
    // Same job, but skip early with continue
    for (int n{1}; n < 50; ++n) {
        if (n % 2 != 0) {
            continue; // not even: skip
        }
        if (n % 3 != 0) {
            continue; // not a multiple of 3: skip
        }
        std::cout << n << ' '; // the real work, at the top level
    }
    std::cout << '\n';
    return 0;
}
