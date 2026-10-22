#include <iostream>

struct Date {
    int year{}, month{}, day{};

    void print() const {
        std::cout << year << '/' << month << '/' << day << '\n';
    }
};

int main() {
    Date today{2026, 2, 26}; // not const
    today.print();           // fine
    return 0;
}
