#include <iostream>
#include <string>

void print(std::string s) { std::cout << s << '\n'; }
void print(char c = '*') { std::cout << c << '\n'; }

int main() {
    print("Hello, world"); // print(std::string)
    print('a');            // print(char)
    print();               // print(char), using the default '*'
    return 0;
}
