#include <iostream>
#include <string>       // to use std::string
// void means the function does not return a value to the caller
void hi_somebody(std::string name)
{
    std::cout << "Hi " << name << '\n';

    // This function does not return a value so no return statement is needed
}
int main()
{
    hi_somebody("Alice"); // function hi_somebody() is called, no value is returned
    hi_somebody("Catherine");
    return 0;
}