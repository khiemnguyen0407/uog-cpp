#include <iostream>

class Foo
{
private:
    int x {};
    int y {};

public:
    Foo(int x, int y)
    {
        this->x = x; // "this" is the pointer to the object under consideration.
        this->y = y;
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