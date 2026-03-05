#include <iostream>
class Date
{
// Any members defined here would default to private

public: // here's our public access specifier

    void print() const // public due to above public: specifier
    {
        // members can access other private members
        std::cout << year << '/' << month << '/' << day;
    }

private: // here's our private access specifier

    int year { 2020 };  // private due to above private: specifier
    int month { 14 }; // private due to above private: specifier
    int day { 10 };   // private due to above private: specifier
};

int main()
{
    Date d{};
    d.print();  // okay, main() allowed to access public members

    return 0;
}