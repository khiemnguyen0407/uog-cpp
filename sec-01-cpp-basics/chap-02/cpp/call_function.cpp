#include <iostream> // for std::cout

void say_hello()    // user-defined function
{
    std::cout << "In say_hello(): Hello there!\n";
}

int main()          // Definition of function main()
{
    std::cout << "Starting main()\n";
    say_hello(); // say_hello() called for the first time
    say_hello(); // say_hello() called for the second time
    std::cout << "Ending main()\n";
    return 0;
}