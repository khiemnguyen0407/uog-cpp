#include <iostream>

class Base {
  public:
    void identify() const { std::cout << "Base::identify()\n"; }
};

class Derived : public Base {
  public:
    void identify() const {
        std::cout << "Derived::identify()\n";
        Base::identify(); // ...and then do what Base does
    }
};

int main() {
    Derived derived{};
    derived.identify();
    return 0;
}
