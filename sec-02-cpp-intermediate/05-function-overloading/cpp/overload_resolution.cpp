#include <iostream>

int add(int x, int y) { return x + y; }
double add(double x, double y) { return x + y; }
double add(double x, double y, double z) { return x + y + z; }

int main() {
    std::cout << add(1, 2) << '\n';     // add(int, int)
    std::cout << add(1.2, 3.4) << '\n'; // add(double, double)

    // add(double, double, double): 1 (an int) and 2.5f (a float)
    // both become doubles
    std::cout << add(1, 2.5f, 1.2) << '\n';
    return 0;
}
