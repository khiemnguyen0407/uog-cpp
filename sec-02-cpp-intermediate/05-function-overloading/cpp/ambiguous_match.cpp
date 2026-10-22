#include <iostream>

void print(int x) { std::cout << "int " << x << '\n'; }
void print(double x) { std::cout << "double " << x << '\n'; }

int main() {
    print(5);   // exact match: print(int)
    print(5.0); // exact match: print(double)
    print(5L);  // a long: converts to int AND to double. Which?
    return 0;
}
