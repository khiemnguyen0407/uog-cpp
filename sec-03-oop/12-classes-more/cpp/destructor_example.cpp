#include <iostream>

class Simple
{
private:
    int id {};

public:
    Simple(int id) : id { id }
    {
        std::cout << "Constructing Simple " << id << '\n';
    }

    ~Simple() // here's our destructor
    {
        std::cout << "Destructing Simple " << id << '\n';
    }

    int get_ID() const { return id; }
};

int main()
{
    // Allocate a Simple
    Simple simple1{ 42 };
    {
        Simple simple2{ 24 };
    } // simple2 dies here

    return 0;
} // simple1 dies here