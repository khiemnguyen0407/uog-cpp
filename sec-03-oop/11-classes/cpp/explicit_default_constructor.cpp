#include <iostream>

class Foo
{
    int x {};
    int y {};

public:
    // If we don't have this default constructor, Foo foo{} leads to error.
    // Remove this line of code to see the error.
    Foo() = default; // generates an explicitly defaulted default constructor

    Foo(int x, int y) : x { x }, y { y } {
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }
};

int main()
{
    Foo foo{}; // calls Foo() default constructor

    return 0;
}