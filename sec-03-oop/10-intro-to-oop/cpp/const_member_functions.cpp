#include <iostream>

struct Date
{
    int year {}, month {}, day {};
    void print() const // now a const member function
    {
        std::cout << year << '/' << month << '/' << day;
        double another_year {42};
        another_year += 1;
    }
};

int main()
{
    const Date today { 2020, 10, 14 }; // const
    today.print();  // ok: const object can call const member function

    return 0;
}