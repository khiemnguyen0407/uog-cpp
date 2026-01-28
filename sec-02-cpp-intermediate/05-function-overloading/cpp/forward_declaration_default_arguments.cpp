#include <iostream>

void print(int x, int y=4);     // forward declaration, with default argument

int main()
{
    print(3);

    return 0;
}
// function definition, no need to make default argument here.
void print(int x, int y)        
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}