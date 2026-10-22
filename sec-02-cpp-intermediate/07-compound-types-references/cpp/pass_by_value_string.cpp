#include <iostream>
#include <string>

void print_value(std::string y) { // y is a copy of x
    std::cout << y << '\n';
} // the copy is destroyed here

int main() {
    std::string x{"My name is Khiem. What's your name?"};
    print_value(x); // copies every character of x: expensive!
    return 0;
}
