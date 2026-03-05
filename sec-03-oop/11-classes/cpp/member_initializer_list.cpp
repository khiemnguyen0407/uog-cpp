#include <iostream>

class Foo
{
private:
    int x {};
    int y {};

public:
    Foo(int x, int y)
        : x { x }, y { y } // here's our member initialization list
    {
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }

    void print() const
    {
        std::cout << "Foo(" << x << ", " << y << ")\n";
    }
};

int main()
{
    Foo foo{ 6, 7 };
    foo.print();

    return 0;
}