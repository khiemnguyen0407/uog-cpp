#include <iostream>

int get_value_from_user() {
    std::cout << "Enter an integer: ";
    int input{};
    std::cin >> input;
    return input;
}

void print_diff(int x, int y) {
    std::cout << x << " - " << y << " = " << x - y << '\n';
}

int main() {
    print_diff(get_value_from_user(), get_value_from_user());
    return 0;
}
