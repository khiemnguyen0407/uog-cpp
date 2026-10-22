#include <iostream>
#include <string> // for std::string

int main() {
    std::string name{"Khiem"};
    std::cout << "Hello, " << name << '\n';

    name = "Ada Lovelace"; // it can change, and grow
    std::cout << "Hello, " << name << '\n';
    std::cout << name << " has " << name.length() << " characters\n";
    return 0;
}
