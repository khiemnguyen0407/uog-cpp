#include <iostream>

int main() {
    int count{0};            // how many times we've looped
    bool keep_looping{true}; // controls whether the loop ends
    while (keep_looping) {
        std::cout << "Enter e to exit: ";
        char ch{};
        std::cin >> ch;

        if (ch == 'e') {
            keep_looping = false;
        } else {
            ++count;
            std::cout << "We've looped " << count << " times\n";
        }
    }
    return 0;
}
