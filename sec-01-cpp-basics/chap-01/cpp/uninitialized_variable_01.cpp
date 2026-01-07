#include <iostream>
int main()
{
    // define an integer variable named x
    int x;                  // this variable is uninitialized 
                            // because we haven't given it a value

    std::cout << x << '\n'; // who knows what we'll get, because x is uninitialized

    int y {};       // initialized to 0
    std::cout << y << '\n';
    
    int z { 42 };   // initialized to 42
    std::cout << z << '\n';

    return 0;
}
// my compiler always give x=0. To see the warning from the compiler, use
// g++ -Wall -Wextra uninitialized_variable_01.cpp