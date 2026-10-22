#include <iostream>

class Foo {
  private:
    int x{}, y{};

  public:
    Foo(int x, int y) { // same names as the members...
        this->x = x;    // ...so use this-> for the members
        this->y = y;
    }

    void print() const { std::cout << "Foo(" << x << ", " << y << ")\n"; }
};

int main() {
    Foo foo{6, 7};
    foo.print();
    return 0;
}
