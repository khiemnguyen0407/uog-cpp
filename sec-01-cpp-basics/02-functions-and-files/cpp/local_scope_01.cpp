#include <iostream>

void print_x() {
    int x{42}; // this x belongs to print_x()
    std::cout << "In print_x(): x = " << x << '\n';
}

int main() {
    int x{7}; // a different x, belonging to main()
    print_x();
    std::cout << "In main():    x = " << x << '\n';
    return 0;
}
