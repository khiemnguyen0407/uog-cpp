#include <iostream>

class Foo
{
private:
    int x {};
    int y {};

public:
    // if x_out is named as x, we have shadowing
    Foo(int x_out, int y_out)
    {
        x = x_out; // we don't have self.x
        y = y_out;
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