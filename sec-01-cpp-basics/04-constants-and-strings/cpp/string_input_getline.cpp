#include <iostream>
#include <string>

int main() {
    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age; // leaves Enter in the buffer

    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name); // skip it, then read a line

    std::cout << "Hello, " << name << ", age " << age << '\n';
    return 0;
}
