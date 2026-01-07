#include <iostream>
void say_hi()   // void means the function does not return a value to the caller
{
    std::cout << "Hi" << '\n';
    return; // tell compiler to return to the caller 
    /* this is redundant since the return will happen 
       at the end of the function anyway! */
}   // function will return to caller here

int main()
{
    say_hi();
    return 0;
}