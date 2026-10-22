#include <iostream>

int main() {
    for (int count{0}; count < 10; ++count) {
        if (count % 2 == 1) { // odd number?
            continue;         // skip the rest of this iteration
        }
        std::cout << count << ' ';
    } // continue jumps to here, then ++count runs
    std::cout << '\n';
    return 0;
}
