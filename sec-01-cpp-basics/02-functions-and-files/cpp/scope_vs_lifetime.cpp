#include <iostream>

void second_function() {
    // x is alive, but OUT OF SCOPE here:
    // the name x cannot be used in this function.
}

void first_function() {
    int x{10}; // x's scope and lifetime start here
    second_function();
    std::cout << x << '\n'; // x is in scope again
} // x's scope and lifetime end here

int main() {
    first_function();
    return 0;
}
