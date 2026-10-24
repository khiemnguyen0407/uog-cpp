#include <iostream>

int main() {
    std::cout << "Enter two numbers: ";

    int x{};
    std::cin >> x;
    std::cout << "You entered " << x << '\n';

    int y{};
    std::cin >> y;
    std::cout << "You entered " << y << '\n';
    return 0;
}
