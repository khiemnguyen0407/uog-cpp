#include <iostream>

struct Date
{
    int year {}, month {}, day {};
    void print() const {// const
        std::cout << year << '/' << month << '/' << day;
    }
};
int main()
{
    Date today { 2020, 10, 14 }; // non-const
    today.print();  // ok: can call const member function on non-const object

    return 0;
}