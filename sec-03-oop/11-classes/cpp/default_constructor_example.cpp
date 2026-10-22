#include <iostream>

class Foo {
  public:
    Foo() { std::cout << "Foo default constructed\n"; }
};

int main() {
    Foo foo1{}; // value initialization: calls Foo()
    Foo foo2;   // default initialization: also calls Foo()
    return 0;
}
