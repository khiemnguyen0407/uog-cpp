#include <iostream>

int main() {
    int a = 4.7; // copy-initialization: silently becomes 4
    std::cout << a << '\n';

    int b{4.7}; // list-initialization: compile error!
    return 0;
}
