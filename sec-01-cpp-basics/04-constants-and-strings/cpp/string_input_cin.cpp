#include <iostream>
#include <string>

int main() {
    std::cout << "Enter your full name: ";
    std::string name{};
    std::cin >> name; // stops at the first space!

    std::cout << "Hello, " << name << '\n';
    return 0;
}
