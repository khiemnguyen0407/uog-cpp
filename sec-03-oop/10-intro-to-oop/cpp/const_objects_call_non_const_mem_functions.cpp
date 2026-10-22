#include <iostream>

struct Date {
    int year{}, month{}, day{};
    void print() { // not const
        std::cout << year << '/' << month << '/' << day << '\n';
    }
};

int main() {
    const Date today{2026, 2, 26};
    today.print(); // error: print() might modify today
    return 0;
}
