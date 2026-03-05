#include <iostream>
#include <string>

const std::string& get_program_name()
{
    // now a non-static local variable, destroyed when function ends
    const std::string str_program_name { "Calculator" }; 
    return str_program_name;
}

int main()
{
    std::cout << "This program is named " << get_program_name(); // undefined behavior

    return 0;
}