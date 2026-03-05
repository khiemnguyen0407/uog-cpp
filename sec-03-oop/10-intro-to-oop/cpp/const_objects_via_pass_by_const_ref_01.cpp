#include <iostream>

struct Date
{
    int year {}, month {}, day {};
    void print() {  // non-const
        std::cout << year << '/' << month << '/' << day;
    }
};

void do_something(const Date& date) {
    date.print();
}

int main()
{
    Date today { 2020, 10, 14 }; // non-const
    today.print();
    do_something(today);

    return 0;
}