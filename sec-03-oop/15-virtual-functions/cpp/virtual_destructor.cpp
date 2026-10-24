#include <iostream>

class Base {
  public:
    ~Base() { std::cout << "~Base()\n"; } // NOT virtual
    virtual void hello() const { std::cout << "Hello from Base\n"; }
};
class Derived : public Base {
  public:
    ~Derived() { std::cout << "~Derived()\n"; } // cleans up Derived's part
};

int main() {
    Base* ptr{new Derived{}}; // a Base pointer to a heap Derived
    delete ptr;               // which destructors run?
    return 0;
}
