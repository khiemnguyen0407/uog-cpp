// Member function version
#include <iostream>

struct Date
{
    int year {};        // We don't use m_ here for struct. Generally, we don't
    int month {};       // want to write constructor for struct. Then, there is 
    int day {};         // NO SHADOWING of variables (we talk later in `class`)

    void print() // defines a member function named print
    {
        std::cout << year << '/' << month << '/' << day;
    }
};

int main()
{
    Date today { 2026, 02, 26 }; // aggregate initialize our struct
    today.day = 16; // member variables accessed using member selection operator (.)
    today.print();  // member functions also accessed using member selection operator (.)
    std::cout << '\n';
    return 0;
}