#include <iostream>

int main() {
    std::cout << "Enter your height (in cm): ";
    int height{};
    std::cin >> height;

    if (height >= 140) {
        std::cout << "You are tall enough to ride.\n";
    } else { // the braces make both lines part of the else
        std::cout << "You are not tall enough to ride.\n";
        std::cout << "Too bad!\n";
    }
    return 0;
}
