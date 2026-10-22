#include <iostream>

int main() {
    while (true) { // loops forever...
        std::cout << "Loop again (y/n)? ";
        char c{};
        std::cin >> c;
        if (c == 'n') {
            return 0; // ...until this ends main()
        }
    }
}
