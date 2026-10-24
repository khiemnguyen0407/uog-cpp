#include <iostream>

class Base {
  public:
    void print_base() const { std::cout << "a Base\n"; }
};

class Derived : public Base {
  public:
    void print_base() const = delete; // makes no sense for a Derived
};

int main() {
    Derived derived{};
    derived.print_base(); // error: deleted in Derived
    return 0;
}
