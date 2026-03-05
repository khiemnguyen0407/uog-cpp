#include <iostream>
#include <string_view>

struct Date
{
    int year {}; int month {}; int day {};  // Do not write like this! Save space for slide
    void print() {
        std::cout << year << '/' << month << '/' << day;
    }
    void print(std::string_view prefix) {
        std::cout << prefix << year << '/' << month << '/' << day;
    }
};

int main()
{
    Date today { 2020, 10, 14 };
    today.print(); // calls Date::print()
    std::cout << '\n';
    today.print("The date is: "); // calls Date::print(std::string_view)
    std::cout << '\n';

    return 0;
}