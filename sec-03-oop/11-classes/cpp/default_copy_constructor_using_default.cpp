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

    // Explicitly request default copy constructor
    Fraction(const Fraction& fraction) = default;

    void print() const
    {
        std::cout << "Fraction(" << numerator << ", " << denominator << ")\n";
    }
};

int main()
{
    Fraction f { 5, 3 };
    Fraction f_copy { f };

    f.print();
    f_copy.print();

    return 0;
}