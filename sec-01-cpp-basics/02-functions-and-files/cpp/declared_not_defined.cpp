#include <iostream>

int add(int x, int y); // declared...

int main() {
    std::cout << "3 + 4 = " << add(3, 4) << '\n';
    return 0;
}

// ...but never defined anywhere!
