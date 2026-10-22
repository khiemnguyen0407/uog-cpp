#include <iostream>
#include <string>

int main() {
    std::string first{"Khiem"};
    std::string last{"Nguyen"};
    std::string full{first + " " + last}; // join with +

    std::cout << full << '\n';
    std::cout << "First letter: " << full[0] << '\n'; // from 0

    if (first == "Khiem") { // compare with ==
        std::cout << "Hello, lecturer!\n";
    }
    return 0;
}
