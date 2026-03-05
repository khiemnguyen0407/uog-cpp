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

    // Copy constructor
    Fraction(const Fraction& fraction)
        // Initialize our members using the corresponding member of the parameter
        : numerator{ fraction.numerator }
        , denominator{ fraction.denominator }
    {
        std::cout << "Copy constructor called\n"; // just to prove it works
    }

    void print() const
    {
        std::cout << "Fraction(" << numerator << ", " << denominator << ")\n";
    }
};

int main()
{
    Fraction f { 5, 3 };  // Calls Fraction(int, int) constructor
    Fraction f_copy { f }; // Calls Fraction(const Fraction&) copy constructor

    f.print();
    f_copy.print();

    return 0;
}