#include <iostream>

class Base {
  public:
    int id{};
    Base(int id = 0) : id{id} { std::cout << "  Base constructed\n"; }
};

class Derived : public Base {
  public:
    double value{};
    Derived(double value = 0.0) : value{value} {
        std::cout << "  Derived constructed\n";
    }
};

int main() {
    std::cout << "Creating a Base:\n";
    Base base{};
    std::cout << "Creating a Derived:\n";
    Derived derived{};
    return 0;
}
