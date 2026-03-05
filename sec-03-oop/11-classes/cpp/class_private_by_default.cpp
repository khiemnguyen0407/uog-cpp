#include <iostream>

class Date // now a class instead of a struct
{
    // class members are private by default, can only be accessed by other members
    int year {};     // private by default
    int month {};    // private by default
    int day {};      // private by default

    void print() const // private by default
    {
        // private members can be accessed in member functions
        std::cout << year << '/' << month << '/' << day;
    }
};

int main()  // main is a part of public
{
    // Date today { 2020, 10, 14 }; // compile error: can no longer use aggregate initialization

    // private members can not be accessed by the public
    // You cannot do something silly like this.
    /*
    today.m_day = 42;   // compile error: the m_day member is private. 
    today.m_month = 42; // compile error: the m_month member is private.
    today.m_year = 42;  // compile error: the m_year member is private.
    today.print();      // compile error: the print() member function is private.
    */
    return 0;
}