#include <iostream>
#include <string_view>

void print(std::string_view s) {
    std::cout << s << '\n';
}
void print(char c = ' ') {
    std::cout << c << '\n';
}
int main()
{
    print("Hello, world"); // resolves to print(std::string_view)
    print('a');            // resolves to print(char)
    print();               // resolves to print(char)

    return 0;
}