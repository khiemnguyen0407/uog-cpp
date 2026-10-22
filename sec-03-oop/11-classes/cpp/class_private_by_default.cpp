#include <iostream>

class Date { // now a class: members are private by default
    int year{}, month{}, day{};

    void print() const {
        std::cout << year << '/' << month << '/' << day << '\n';
    }
};

int main() {
    Date today{2026, 2, 26}; // error: not an aggregate any more
    today.day = 42;          // error: day is private
    today.print();           // error: print() is private
    return 0;
}
