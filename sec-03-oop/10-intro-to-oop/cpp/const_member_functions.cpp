#include <iostream>

struct Date {
    int year{}, month{}, day{};

    void print() const { // a const member function
        std::cout << year << '/' << month << '/' << day << '\n';
        int next_year{year + 1}; // locals can still change
        ++next_year;
    }
};

int main() {
    const Date today{2026, 2, 26};
    today.print(); // fine
    return 0;
}
