#include <iostream>

struct Date {
    int year{}, month{}, day{};
};

void print(const Date& date) { // a non-member function
    std::cout << date.year << '/' << date.month << '/' << date.day << '\n';
}

int main() {
    Date today{2026, 2, 26};
    today.day = 27; // select a member with .
    print(today);   // pass the object as an argument
    return 0;
}
