#include <iostream>

int main() {
    int width;                  // define a variable named width
    width = 5;                  // assign the value 5 to width
    std::cout << width << '\n'; // prints 5

    width = 7;                  // assign a new value: 5 is gone
    std::cout << width << '\n'; // prints 7
    return 0;
}
