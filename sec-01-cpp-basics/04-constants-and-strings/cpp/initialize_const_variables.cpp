#include <iostream>

int main() {
    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    const int const_age{age}; // fine: initialized from a variable

    age = 5;       // fine: age is not const
    const_age = 6; // error: const_age is const
    return 0;
}
