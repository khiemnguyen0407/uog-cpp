#include <iostream>

class Base {
  public:
    void identify() const { std::cout << "Base::identify()\n"; }
};

class Derived : public Base {
  public:
    void identify() const { std::cout << "Derived::identify()\n"; }
};

int main() {
    Base base{};
    base.identify();
    Derived derived{};
    derived.identify(); // Derived's own version hides Base's
    return 0;
}
