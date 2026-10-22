class Fraction {
  private:
    int numerator{0}, denominator{1};

  public:
    Fraction(int numerator = 0, int denominator = 1)
        : numerator{numerator}, denominator{denominator} {}

    Fraction(const Fraction& other) = delete; // no copies allowed
};

int main() {
    Fraction f{5, 3};
    Fraction f_copy{f}; // error: the copy constructor is deleted
    return 0;
}
