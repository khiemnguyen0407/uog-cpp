#include <iostream>

void print_numbers(int x=10, int y=20, int z=30)
{
    std::cout << "Values: " << x << " " << y << " " << z << '\n';
}

int main()
{
    print_numbers(1, 2, 3); // all explicit arguments
    print_numbers(1, 2); // rightmost argument defaulted
    print_numbers(1); // two rightmost arguments defaulted
    print_numbers(); // all arguments defaulted

    return 0;
}