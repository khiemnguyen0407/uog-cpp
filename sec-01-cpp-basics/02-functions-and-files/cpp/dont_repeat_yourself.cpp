#include <iostream>

int get_value_from_user() {
    std::cout << "Enter an integer: ";
    int input{};
    std::cin >> input;
    return input;
}

int main() {
    int x{get_value_from_user()}; // first call
    int y{get_value_from_user()}; // second call

    std::cout << "Sum: " << x + y << '\n';
    return 0;
}
