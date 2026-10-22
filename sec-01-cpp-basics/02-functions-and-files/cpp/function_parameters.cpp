#include <iostream>

// No parameters: needs nothing from the caller
void say_hello() { std::cout << "Hello World\n"; }

// One parameter: the caller supplies x
void print_value(double x) { std::cout << x << '\n'; }

// Two parameters: the caller supplies x and y
double add(double x, double y) { return x + y; }

int main() {
    say_hello();                        // no arguments
    print_value(6.5);                   // one argument
    std::cout << add(2.0, 3.5) << '\n'; // two arguments
    return 0;
}
