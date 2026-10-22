#include <iostream>

struct Date {
    int year{}, month{}, day{}; // public by default

    void print() const { // public by default
        std::cout << year << '/' << month << '/' << day << '\n';
    }
};

int main() { // main() is not a member: it's "the public"
    Date today{2026, 2, 26};
    today.day = 42;   // allowed: day is public...
    today.month = 42; // ...so nothing stops nonsense like this
    today.year = -42;
    today.print();
    return 0;
}
