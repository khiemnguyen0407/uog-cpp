#include <iostream>

int main() {
    // Illegal: foo() is defined inside main()
    void foo() { std::cout << "foo!\n"; }

    foo();
    return 0;
}
