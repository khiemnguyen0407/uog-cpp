#include <iostream>

class Foo {
  private:
    int x{};   // default member initializer: ignored, see below
    int y{42}; // default member initializer: used
    int z;     // no initializer at all: garbage!

  public:
    Foo(int x)
        : x{x} // member initializer list: wins over x's default
    {}

    void print() const {
        std::cout << "Foo(" << x << ", " << y << ", " << z << ")\n";
    }
};

int main() {
    Foo foo{6};
    foo.print();
    return 0;
}
