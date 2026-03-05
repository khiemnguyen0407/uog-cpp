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

Fraction generate_fraction(int n, int d)
{
    Fraction f{ n, d };
    return f;       // one copy constructor invoked
}

int main()
{
    Fraction f1 {};
    print_fraction(f1); // one copy constructor invoked
    Fraction f2 { generate_fraction(1, 2) }; // Fraction is returned using copy constructor

    print_fraction(f2); // f is copied into the function parameter using copy constructor

    return 0;
}