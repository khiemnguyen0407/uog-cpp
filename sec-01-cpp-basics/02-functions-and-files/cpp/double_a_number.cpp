#include <iostream>

int get_value_from_user() {
    std::cout << "Enter an integer: ";
    int input{};
    std::cin >> input;
    return input;
}

void print_double(int value) { // one int parameter
    std::cout << value << " x 2 = " << value * 2 << '\n';
}

int main() {
    int num{get_value_from_user()};
    print_double(num);

    print_double(get_value_from_user());
    return 0;
}
