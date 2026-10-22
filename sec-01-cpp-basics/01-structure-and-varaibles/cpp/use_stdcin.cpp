#include <iostream> // for std::cout and std::cin

int main() {
    std::cout << "Enter a number: "; // prompt the user

    int x{};       // a variable to hold the input
    std::cin >> x; // read a number into x

    std::cout << "You entered " << x << '\n';
    return 0;
}
