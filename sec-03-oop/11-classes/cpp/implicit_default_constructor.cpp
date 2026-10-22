class Foo {
  private:
    int x{}, y{};
    // no constructors declared
};

int main() {
    Foo foo{}; // fine: the compiler wrote a default constructor for us
    return 0;
}
