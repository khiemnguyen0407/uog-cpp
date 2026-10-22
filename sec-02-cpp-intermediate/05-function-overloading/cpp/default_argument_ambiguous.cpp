#include <iostream>

void print(int x) { std::cout << x << '\n'; }
void print(int x, int y = 10) { std::cout << x << ' ' << y << '\n'; }

int main() {
    print(1, 2); // fine: only print(int, int) takes two arguments
    print(1);    // error: print(int) or print(int, int = 10)?
    return 0;
}
