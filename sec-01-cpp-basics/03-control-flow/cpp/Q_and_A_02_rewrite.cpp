#include <iostream>

int main() {
    int count{0}; // how many times we've looped
    while (true) {
        std::cout << "Enter e to exit: ";
        char ch{};
        std::cin >> ch;

        if (ch == 'e') {
            break;
        }
        ++count;
        std::cout << "We've looped " << count << " times\n";
    }
    return 0;
}
