#include <iostream>

int main() {
    switch (1 - 2 + 3 - 4 + 5) { // any integer expression
    case 3:
        std::cout << "Three\n";
        break;
    case 2 + 2: // a constant expression works as a label
        std::cout << "Four\n";
        break;
    default:
        std::cout << "Something else\n";
        break;
    }
    return 0;
}
