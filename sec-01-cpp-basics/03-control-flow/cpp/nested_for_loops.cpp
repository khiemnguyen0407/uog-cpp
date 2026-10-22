#include <iostream>

int main() {
    for (char c{'a'}; c <= 'e'; ++c) { // outer loop: letters
        std::cout << c;                // print the letter first

        for (int i{0}; i < 3; ++i) { // inner loop: numbers
            std::cout << i;
        }
        std::cout << '\n';
    }
    return 0;
}
