#include <iostream>

class Fraction {
  private:
    int numerator{0}, denominator{1};

  public:
    Fraction(int numerator = 0, int denominator = 1)
        : numerator{numerator}, denominator{denominator} {}

    void print() const { std::cout << numerator << '/' << denominator << '\n'; }
};

int main() {
    Fraction f{5, 3};   // calls Fraction(int, int)
    Fraction f_copy{f}; // which constructor is this?
    f.print();
    f_copy.print();
    return 0;
}
