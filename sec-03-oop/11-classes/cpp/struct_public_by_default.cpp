#include <iostream>

struct Date
{
    // struct members are public by default, can be accessed by anyone
    int year {};       // public by default
    int month {};      // public by default
    int day {};        // public by default

    void print() const // public by default
    {
        // public members can be accessed in member functions of the class type
        std::cout << year << '/' << month << '/' << day;
    }
};

// non-member function main is part of "the public"
int main()  // main is not a member of Date, it is part of `public`.
{
    Date today { 2020, 10, 14 }; // aggregate initialize our struct

    // public members can be accessed by the public
    today.day = 42;     // okay: the day member is public. That's why it's dangerous
    today.month = 42;   // okay: the month member is public. That's why it's dangerous
    today.year = -42;   // okay: the year member is public. That's why it's dangerous
    today.print();      // okay: the print() member function is public

    return 0;
}