#include <iostream>

class Base {
  public:
    virtual ~Base() { std::cout << "~Base()\n"; } // virtual now
    virtual void hello() const { std::cout << "Hello from Base\n"; }
};
class Derived : public Base {
  public:
    ~Derived() override { std::cout << "~Derived()\n"; }
};

int main() {
    Base* ptr{new Derived{}};
    delete ptr;
    return 0;
}
