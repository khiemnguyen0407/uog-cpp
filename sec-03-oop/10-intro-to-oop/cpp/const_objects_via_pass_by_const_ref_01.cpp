#include <iostream>

struct Date {
    int year{}, month{}, day{};

    void print() { // not const
        std::cout << year << '/' << month << '/' << day << '\n';
    }
};

void do_something(const Date& date) {
    date.print(); // error: date is const in here
}

int main() {
    Date today{2026, 2, 26}; // not const
    do_something(today);
    return 0;
}
