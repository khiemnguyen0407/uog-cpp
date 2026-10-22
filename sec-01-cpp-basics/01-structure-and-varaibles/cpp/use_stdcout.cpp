#include <iostream> // for std::cout

int main() {
    std::cout << "Hello world!\n"; // print some text
    std::cout << 4 << '\n';        // print a number

    int x{5};
    std::cout << x << '\n'; // print the value of x

    // Chain several outputs in one statement
    std::cout << "I am " << "Khiem " << "Nguyen" << '\n';

    int planets{8};
    int suns{1};
    std::cout << planets << " planets and " << suns << " sun\n";
    return 0;
}
