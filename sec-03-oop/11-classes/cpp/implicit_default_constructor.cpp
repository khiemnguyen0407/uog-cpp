#include <iostream>

class Foo {
private:
    int x{};
    int y{};
    // Note: no constructors declared
};

int main()
{
    Foo foo{};  // implicit default constructor is used
    return 0;
}