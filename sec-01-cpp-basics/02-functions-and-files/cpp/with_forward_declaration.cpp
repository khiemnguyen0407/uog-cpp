#include <iostream>

int add(int x, int y); // forward declaration (note the ;)

int main() {
    std::cout << "3 + 4 = " << add(3, 4) << '\n'; // OK now
    return 0;
}

int add(int x, int y) { // the definition can come later
    return x + y;
}
