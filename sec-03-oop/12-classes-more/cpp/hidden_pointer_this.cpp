#include <iostream>

class Simple
{
private:
    double value{};

public:
    Simple(double value)
        : value{ value }
    {
    }

    double get_value() const { 
        return this->value;     // equivallently, we can write "return value;"
    }
    void set_value(int value) { 
        this->value = value;
    } 

    void print() const { std::cout << this->value; } // use `this` pointer to access the implicit object and operator-> to select member m_id
};

int main()
{
    Simple simple { 0 };
    std::cout << simple.get_value() << '\n';
    simple.set_value(42.0);
    simple.print();
    std::cout << '\n';
    return 0;
}