#include <iostream>

class Calculator {
  private:
    double value{};

  public:
    Calculator(double value) : value{value} {}

    Calculator& add(double x) {
        value += x;
        return *this; // return the implicit object itself
    }
    Calculator& mult(double x) {
        value *= x;
        return *this;
    }
    double get_value() const { return value; }
};

int main() {
    Calculator calc{42};
    calc.add(5).add(-3).mult(4); // method chaining
    std::cout << calc.get_value() << '\n';
    return 0;
}
