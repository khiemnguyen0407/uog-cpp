#include <iostream>
struct Employee
{
    int id {};          // default initialization
    int age {42};       // default initialization
    double wage {};     // default initialization
};

int main()
{   
    // copy-list initialization using braced list
    Employee frank = { 1, 32, 60000.0 }; 
    // list initialization using braced list (preferred)
    Employee joe { 2, 28, 45000.0 }; 
    // id, age and wage will be initialized by default as above
    Employee khiem {};
    std::cout << "khiem.age = " << khiem.age << "\nkhiem.wage = " << khiem.wage << '\n'; 
    return 0;    
}