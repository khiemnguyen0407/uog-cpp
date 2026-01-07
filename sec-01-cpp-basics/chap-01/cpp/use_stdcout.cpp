#include <iostream> // for std::cout

int main()
{
    std::cout << "Hello world!\n"; // print Hello world! to console
    std::cout << 4; // print 4 to console

    int x{ 5 };             // define integer variable x, initialized with value 5
    std::cout << x;         // print value of x (5) to console
    std::cout << '\n';      // enter a new line

    // chain the output
    std::cout << "I" << " am" << " Khiem" << " Nguyen" << '\n';

    int a { 8 }, b { 1 };
    std::cout << "Hello " << a << " planets and " << b << " sun.\n";

    return 0;
}