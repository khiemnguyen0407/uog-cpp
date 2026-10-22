class Foo {
  private:
    int x{}, y{};

  public:
    Foo(int x, int y) : x{x}, y{y} {} // removes the implicit default one
};

int main() {
    Foo foo1{1, 2}; // fine: uses Foo(int, int)
    Foo foo2{};     // error: there is no default constructor now
    return 0;
}
