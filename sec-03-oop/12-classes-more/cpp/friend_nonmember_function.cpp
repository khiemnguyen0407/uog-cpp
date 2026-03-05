#include <iostream>

class Accumulator
{
private:
    double value { 0 };

public:
    void add(double value) { this->value += value; }
    // Here is the friend declaration that makes non-member function 
    // void print(const Accumulator& accumulator) a friend of Accumulator
    friend void print(const Accumulator& accumulator);
};

void print(const Accumulator& accumulator)
{
    // Because print() is a friend of Accumulator
    // it can access the private members of Accumulator
    std::cout << accumulator.value;
}

int main()
{
    Accumulator acc{};
    acc.add(42);    // add 42 to the accumulator
    print(acc);     // call the print() non-member function
    std::cout << '\n';
    return 0;
}