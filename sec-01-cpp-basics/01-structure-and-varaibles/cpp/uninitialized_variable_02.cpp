#include <iostream>

void dirty_the_memory() {
    int a{42}; // these values are left behind in memory...
    int b{24};
    int c{66};
    std::cout << "Leaving behind " << a << ", " << b << ", " << c << '\n';
}

void see_the_junk() {
    int x; // uninitialized: x may land where a, b or c were
    std::cout << "Uninitialized x holds " << x << '\n';
}

int main() {
    dirty_the_memory();
    see_the_junk();
    return 0;
}
