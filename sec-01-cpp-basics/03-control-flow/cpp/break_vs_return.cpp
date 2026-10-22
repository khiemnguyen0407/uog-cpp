#include <iostream>

int break_or_return() {
    while (true) {
        std::cout << "Type b (break) or r (return): ";
        char ch{};
        std::cin >> ch;
        if (ch == 'b') {
            break; // continue after the loop
        }
        if (ch == 'r') {
            return 1; // leave the whole function now
        }
    }
    std::cout << "We broke out of the loop\n";
    return 0;
}

int main() {
    int result{break_or_return()};
    std::cout << "It returned " << result << '\n';
    return 0;
}
