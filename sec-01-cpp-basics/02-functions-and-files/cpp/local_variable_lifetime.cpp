#include <iostream>

void print_double(int value) { // value is created here
    int result{value * 2};     // result is created here
    std::cout << result << '\n';
} // result, then value, are destroyed here

int main() {
    int number{21}; // number is created here
    print_double(number);
    return 0;
} // number is destroyed here
