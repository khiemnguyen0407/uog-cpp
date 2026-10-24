#include <iostream>

class A {
  public:
    A() { std::cout << "A constructed\n"; }
    ~A() { std::cout << "A destroyed\n"; }
};

class B : public A {
  public:
    B() { std::cout << "B constructed\n"; }
    ~B() { std::cout << "B destroyed\n"; }
};

class C : public B {
  public:
    C() { std::cout << "C constructed\n"; }
    ~C() { std::cout << "C destroyed\n"; }
};

int main() {
    C c{};
    return 0;
} // c is destroyed here
