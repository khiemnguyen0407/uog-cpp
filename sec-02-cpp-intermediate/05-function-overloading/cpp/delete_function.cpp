#include <iostream>

void print_int(int x) { std::cout << x << '\n'; }

void print_int(char) = delete; // calling these is now an error
void print_int(bool) = delete;

int main() {
    print_int(97);  // fine
    print_int('a'); // error: use of deleted function
    return 0;
}
