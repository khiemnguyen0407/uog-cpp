#include <iostream>
#include <string>

int main() {
    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin, name); // gets the leftover Enter

    std::cout << "Hello, " << name << ", age " << age << '\n';
    return 0;
}
