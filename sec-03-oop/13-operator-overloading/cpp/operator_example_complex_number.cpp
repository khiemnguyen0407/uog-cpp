#include <iostream>

class ComplexNumber {
  private:
    double real{}, imag{};

  public:
    ComplexNumber(double real, double imag) : real{real}, imag{imag} {}
};

int main() {
    ComplexNumber a{42, 24};
    ComplexNumber b{24, 42};
    std::cout << a + b << '\n'; // error: no + and no << for ComplexNumber
    return 0;
}
