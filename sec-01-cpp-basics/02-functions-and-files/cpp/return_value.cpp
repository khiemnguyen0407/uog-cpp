#include <iostream>

int get_value_from_user() { // returns an int
    std::cout << "Enter an integer: ";
    int input{};
    std::cin >> input;
    return input; // send a copy of input back
}

int main() {
    // num is initialised with the return value
    int num{get_value_from_user()};

    std::cout << num << " x 2 = " << num * 2 << '\n';
    return 0;
}
