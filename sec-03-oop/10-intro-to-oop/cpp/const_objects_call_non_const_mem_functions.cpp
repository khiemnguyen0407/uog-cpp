#include <iostream>

struct Date
{
    int year {}, month {}, day {};
    void print()     {
        std::cout << year << '/' << month << '/' << day;
    }
};

int main()
{
    const Date today { 2020, 10, 14 }; // const
    // today.print();  // compile error: can't call non-const member function
    return 0;
}