#include <iostream>

class Foo {
  private:
    int x{}, y{};

  public:
    Foo(int x_in, int y_in) { // different names, to avoid shadowing
        x = x_in;             // assign in the body, like Python
        y = y_in;
    }

    void print() const { std::cout << "Foo(" << x << ", " << y << ")\n"; }
};

int main() {
    Foo foo{6, 7};
    foo.print();
    return 0;
}
