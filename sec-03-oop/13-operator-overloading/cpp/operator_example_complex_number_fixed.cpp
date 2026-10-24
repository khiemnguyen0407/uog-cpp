#include <iostream>

class ComplexNumber {
  private:
    double real{}, imag{};

  public:
    ComplexNumber(double real, double imag) : real{real}, imag{imag} {}

    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber{real + other.real, imag + other.imag};
    }

    friend std::ostream& operator<<(std::ostream& out, const ComplexNumber& z) {
        out << z.real << " + " << z.imag << 'i';
        return out;
    }
};

int main() {
    ComplexNumber a{42, 24};
    ComplexNumber b{24, 42};
    std::cout << a << '\n' << b << '\n' << a + b << '\n'; // all fine now
    return 0;
}
