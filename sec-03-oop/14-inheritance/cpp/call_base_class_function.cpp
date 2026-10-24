#include <iostream>

class Base {
  public:
    void identify() const { std::cout << "Base::identify()\n"; }
};

class Derived : public Base {}; // nothing of its own

int main() {
    Base base{};
    base.identify();
    Derived derived{};
    derived.identify(); // the inherited Base::identify()
    return 0;
}
