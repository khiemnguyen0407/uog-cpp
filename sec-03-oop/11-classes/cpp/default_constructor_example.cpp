#include <iostream>

class Foo
{
public:
    Foo() { // default constructor
        std::cout << "Foo default constructed\n";
    }
};

int main()
{
    Foo foo{}; // No initialization values, calls Foo's default constructor

    // With default constructor, value initialization and default initialization will
    // call the default constructor.
    Foo foo1{}; // value initialization, calls Foo() default constructor
    Foo foo2;   // default initialization, calls Foo() default constructor
    return 0;
}