class Fraction {
  private:
    int numerator{};   // numerator and denominator are PARTS of a Fraction:
    int denominator{}; // created with it, destroyed with it, never shared

  public:
    Fraction(int numerator = 0, int denominator = 1)
        : numerator{numerator}, denominator{denominator} {}
};

int main() {
    Fraction f{3, 4};
    return 0;
}
