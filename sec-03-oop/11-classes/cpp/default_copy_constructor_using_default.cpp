#include <iostream>

class Fraction {
  private:
    int numerator{0}, denominator{1};

  public:
    Fraction(int numerator = 0, int denominator = 1)
        : numerator{numerator}, denominator{denominator} {}

    Fraction(const Fraction& other) = default; // the usual copy, please

    void print() const { std::cout << numerator << '/' << denominator << '\n'; }
};

int main() {
    Fraction f{5, 3};
    Fraction f_copy{f};
    f_copy.print();
    return 0;
}
