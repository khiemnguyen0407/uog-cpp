#include <iostream>
#include <string>

const std::string& get_program_name() // returns a const reference
{
     // has static duration, destroyed at end of program
    static const std::string str_program_name { "Calculator" };

    return str_program_name;
}

int main()
{
    std::cout << "This program is named " << get_program_name();

    return 0;
}