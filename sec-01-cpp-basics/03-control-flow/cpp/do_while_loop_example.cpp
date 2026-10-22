#include <iostream>

int main() {
    int selection{}; // outside the loop: used after it

    do {
        std::cout << "Please make a selection:\n";
        std::cout << "1) Addition\n";
        std::cout << "2) Subtraction\n";
        std::cin >> selection;
    } while (selection < 1 || selection > 2);

    std::cout << "You selected option " << selection << '\n';
    return 0;
}
