#include <iostream>

class Foo {
  private:
    int x{}, y{};

  public:
    Foo() { std::cout << "Foo constructed\n"; } // default constructor

    Foo(int x, int y) // another constructor
        : x{x}, y{y} {
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }
};

int main() {
    Foo foo1{};     // calls Foo()
    Foo foo2{6, 7}; // calls Foo(int, int)
    return 0;
}
