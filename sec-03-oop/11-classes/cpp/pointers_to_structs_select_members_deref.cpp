#include <iostream>

struct Employee
{
    int id{};
    int age{};
    long double wage{};
};

int main()
{
    Employee khiem{ 1, 42, 429999999999999999999.42 };
    Employee* ptr{ &khiem };
    // Not great but works: First dereference ptr, then use member selection
    std::cout << (*ptr).id << '\n'; 

    return 0;
}