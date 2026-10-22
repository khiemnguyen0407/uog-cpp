#include <iostream>

class Foo {
  private:
    int x{}, y{};

  public:
    Foo() = default; // "compiler, please write the usual one"

    Foo(int x, int y) : x{x}, y{y} {}

    void print() const { std::cout << "Foo(" << x << ", " << y << ")\n"; }
};

int main() {
    Foo foo1{}; // fine again
    Foo foo2{6, 7};
    foo1.print();
    foo2.print();
    return 0;
}
