#include <iostream>
#include <string>

struct Date {
    int year{}, month{}, day{};
    void print() { std::cout << year << '/' << month << '/' << day << '\n'; }
    void print(const std::string& prefix) { // an overload
        std::cout << prefix << year << '/' << month << '/' << day << '\n';
    }
};

int main() {
    Date today{2026, 2, 26};
    today.print();                // calls Date::print()
    today.print("The date is: "); // calls Date::print(const std::string&)
    return 0;
}
