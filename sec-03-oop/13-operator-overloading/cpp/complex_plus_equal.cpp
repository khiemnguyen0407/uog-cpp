#include <iostream>

class ComplexNumber {
  private:
    double real{}, imag{};

  public:
    ComplexNumber(double real, double imag) : real{real}, imag{imag} {}

    ComplexNumber& operator+=(const ComplexNumber& other) { // a member:
        real += other.real; // it changes *this...
        imag += other.imag;
        return *this; // ...and returns it
    }

    void print() const { std::cout << real << " + " << imag << "i\n"; }
};
ComplexNumber operator+(ComplexNumber a, const ComplexNumber& b) {
    return a += b; // a is a copy, so changing it is fine
}

int main() {
    ComplexNumber a{1, 2};
    ComplexNumber b{3, 4};
    (a + b).print();
    return 0;
}
