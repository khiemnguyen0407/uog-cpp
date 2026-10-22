#include <iostream>
#include <string>

const std::string& get_program_name() {
    // not static: destroyed when the function returns
    const std::string program_name{"Calculator"};
    return program_name; // returns a reference to a dying object
}

int main() {
    std::cout << "This program is named " << get_program_name() << '\n';
    return 0;
}
