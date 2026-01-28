#include <iostream>

void print_int(int x)
{
    std::cout << x << '\n';
}

void print_int(char) = delete; // calls to this function will halt compilation
void print_int(bool) = delete; // calls to this function will halt compilation

int main()
{
    print_int(97);   // okay

    // print_int('a');  // compile error: function deleted
    // print_int(true); // compile error: function deleted

    // print_int(5.0);  // compile error: ambiguous match

    return 0;
}