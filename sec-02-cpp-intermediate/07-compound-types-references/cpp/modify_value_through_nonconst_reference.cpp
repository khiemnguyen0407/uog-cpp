#include <iostream>

int main() {
    int x{42};
    int& ref{x}; // ref is another name for x

    std::cout << x << ' ' << ref << '\n';

    x = 24; // change x...
    std::cout << x << ' ' << ref << '\n';

    ref = 12; // ...or change it through ref
    std::cout << x << ' ' << ref << '\n';
    return 0;
}
