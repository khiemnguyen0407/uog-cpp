#include <iostream>

class Date       // we changed struct to class
{
public:          // and added this line, which is called an access specifier
    int m_day{};        // we can add "m_" prefixes to each of the member 
    int m_month{};      // names to avoid shadowing. But this is not really necessary
    int m_year{};       // in modern C++.
};

void print_date(const Date& date)
{
    std::cout << date.m_day << '/' << date.m_month << '/' << date.m_year;
}

int main()
{
    Date date{ 4, 10, 21 };
    print_date(date);

    return 0;
}