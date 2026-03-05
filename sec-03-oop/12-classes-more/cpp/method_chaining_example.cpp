#include <iostream>
class Calc
{
private:
    double value{};

public:
    Calc(double value) : value {value} {}
    Calc& add(double value) { this->value += value; return *this; }
    Calc& sub(double value) { this->value -= value; return *this; }
    Calc& mult(double value) { this->value *= value; return *this; }

    int get_value() const { return value; }
};

int main()
{
    Calc calc {42};
    calc.add(5).sub(3).mult(4); // method chaining

    std::cout << calc.get_value() << '\n';
    std::cout << ((42 + 5) - 3) * 4 << '\n';
    return 0;
}