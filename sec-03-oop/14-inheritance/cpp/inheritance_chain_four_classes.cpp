#include <iostream>

class A {
  public:
    A() { std::cout << "  A constructed\n"; }
};

class B : public A {
  public:
    B() { std::cout << "  B constructed\n"; }
};

class C : public B {
  public:
    C() { std::cout << "  C constructed\n"; }
};

class D : public C {
  public:
    D() { std::cout << "  D constructed\n"; }
};

int main() {
    std::cout << "Creating a D:\n";
    D d{};
    return 0;
}
