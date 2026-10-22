#include <iostream>

struct Date {
    int year{}, month{}, day{};

    void print() { // a member function
        std::cout << year << '/' << month << '/' << day << '\n';
    }
};

int main() {
    Date today{2026, 2, 26};
    today.day = 27; // select a member variable with .
    today.print();  // ...and a member function too
    return 0;
}
