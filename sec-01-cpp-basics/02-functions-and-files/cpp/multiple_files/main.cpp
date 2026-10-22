#include <iostream>

int add(int x, int y); // add() is defined in another file

int main() {
    std::cout << "3 + 4 = " << add(3, 4) << '\n';
    return 0;
}
