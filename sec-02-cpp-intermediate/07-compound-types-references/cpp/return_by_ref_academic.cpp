#include <iostream>
#include <string>

const std::string& get_program_name() { // returns a const reference
    // static: created once, lives until the program ends
    static const std::string program_name{"Calculator"};
    return program_name;
}

int main() {
    std::cout << "This program is named " << get_program_name() << '\n';
    return 0;
}
