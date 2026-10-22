#include <iostream>

class Foo {
  private:
    int x{}, y{};

  public:
    Foo(int x = 0, int y = 0) // also a default constructor
        : x{x}, y{y} {
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }
};

int main() {
    Foo foo1{};     // Foo(int, int) with both defaults
    Foo foo2{6, 7}; // Foo(int, int)
    return 0;
}
