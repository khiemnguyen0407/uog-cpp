#include <iostream>
#include <string>

void print_value(std::string& y) { // y is a reference: no copy
    std::cout << y << '\n';
}

int main() {
    std::string x{"Hello, world!"};
    print_value(x); // y is bound to x: cheap
    return 0;
}
