#include <iostream>

class Foo {
  private:
    int x{}, y{};

  public:
    Foo() { std::cout << "Foo constructed\n"; } // a default constructor

    Foo(int x = 1, int y = 2) // ALSO a default constructor!
        : x{x}, y{y} {
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }
};

int main() {
    Foo foo{}; // error: which default constructor?
    return 0;
}
