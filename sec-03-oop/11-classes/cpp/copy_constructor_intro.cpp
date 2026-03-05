#include <iostream>

class Fraction
{
private:
    int numerator{ 0 };
    int denominator{ 1 };

public:
    // Default constructor
    Fraction(int numerator=0, int denominator=1)
        : numerator{numerator}, denominator{denominator}
    {
    }

    void print() const
    {
        std::cout << "Fraction(" << numerator << ", " << denominator << ")\n";
    }
};

int main()
{
    Fraction f { 5, 3 };    // Calls Fraction(int, int) constructor
    Fraction f_copy { f };  // What constructor is used here?
    f.print();
    f_copy.print();

    return 0;
}