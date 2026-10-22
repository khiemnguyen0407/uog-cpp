#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
  private:
    int numerator{0}, denominator{1};

  public:
    Fraction(int numerator = 0, int denominator = 1)
        : numerator{numerator}, denominator{denominator} {}

    Fraction(const Fraction& other) // our own copy constructor
        : numerator{other.numerator}, denominator{other.denominator} {
        std::cout << "Copy constructor called\n"; // just to prove it
    }

    void print() const { std::cout << numerator << '/' << denominator << '\n'; }
};

#endif
