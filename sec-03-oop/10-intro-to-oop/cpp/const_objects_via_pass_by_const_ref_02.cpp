#include <iostream>

struct Date {
    int year{}, month{}, day{};

    void print() const { // now const: the one-word fix
        std::cout << year << '/' << month << '/' << day << '\n';
    }
};

void do_something(const Date& date) {
    date.print(); // fine
}

int main() {
    Date today{2026, 2, 26};
    do_something(today);
    return 0;
}
