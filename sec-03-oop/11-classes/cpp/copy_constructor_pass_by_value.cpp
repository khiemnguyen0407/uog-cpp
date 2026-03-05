#include <iostream>

class Fraction
{
private:
    int numerator{ 0 };
    int denominator{ 1 };

public:
    // Default constructor
    Fraction(int numerator = 0, int denominator = 1)
        : numerator{ numerator }, denominator{ denominator }
    {
    }

    // Copy constructor
    Fraction(const Fraction& fraction)
        : numerator{ fraction.numerator }
        , denominator{ fraction.denominator }
    {
        std::cout << "Copy constructor called\n";
    }

    void print() const
    {
        std::cout << "Fraction(" << numerator << ", " << denominator << ")\n";
    }
};

void print_fraction(Fraction f) // f is pass by value
{
    f.print();
}

int main()
{
    Fraction f{ 5, 3 };

    print_fraction(f); // f is copied into the function parameter using copy constructor

    return 0;
}