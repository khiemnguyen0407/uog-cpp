#include <iostream>
int main()
{
    double x { 42.0 };
    double* ptr{ &x }; // ptr initialized to point at x
    std::cout << *ptr << '\n'; // print the value at the address being pointed to (x's address)
    *ptr = 10;
    std::cout << x << '\n';
    double y{ 24.0 };
    ptr = &y; // // change ptr to point at y
    std::cout << *ptr << '\n'; // print the value at the address being pointed to (y's address)
    *ptr = 12;

    std::cout << y << '\n';
    return 0;
}