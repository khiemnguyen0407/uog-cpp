#include <iostream> // for std::cout

void do_thing_B()
{
    std::cout << "In do_thing_B()\n";
}

void do_thing_A()
{
    std::cout << "Starting do_thing_A()\n";
    do_thing_B();
    std::cout << "Ending do_thing_A()\n";
}

// Definition of function main()
int main()
{
    std::cout << "Starting main()\n";
    do_thing_A();
    std::cout << "Ending main()\n";

    return 0;
}