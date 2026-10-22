#include <iostream>

int main() {
    while (true) { // an intentional infinite loop
        std::cout << "Enter 0 to exit: ";
        int num{};
        std::cin >> num;

        if (num == 0) {
            break;
        }
    }
    std::cout << "We're out!\n";
    return 0;
}
