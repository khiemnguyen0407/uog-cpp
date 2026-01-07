#include <iostream>

// This function has two integer parameters, one named x, and one named y
// The values of x and y are passed in by the caller
void print_two_values(int x, int y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

int main()
{
    print_two_values(6, 7); // This function call has two arguments, 6 and 7

    return 0;
}