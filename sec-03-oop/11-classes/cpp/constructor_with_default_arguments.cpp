#include <iostream>

class Foo
{
private:
    int x { };
    int y { };

public:
    Foo(int x=0, int y=0) // has default arguments
        : x { x }
        , y { y }
    {
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }
};

int main()
{
    Foo foo1{};     // calls Foo(int, int) constructor using default arguments
    Foo foo2{6, 7}; // calls Foo(int, int) constructor

    return 0;
}