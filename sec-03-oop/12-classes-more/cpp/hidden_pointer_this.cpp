#include <iostream>

class Simple {
  private:
    double value{};

  public:
    Simple(double value) : value{value} {}

    double get_value() const { return value; } // same as this->value
    void set_value(double value) { this->value = value; }
    void print() const { std::cout << this->value << '\n'; }
};

int main() {
    Simple simple{0.0};
    std::cout << simple.get_value() << '\n';
    simple.set_value(42.5);
    simple.print();
    return 0;
}
