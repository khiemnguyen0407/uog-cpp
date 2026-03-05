#include <iostream>

// This function "pollutes" the stack memory with non-zero values
void do_dirty_stack() {
    int a[100];
    for(int i = 0; i < 100; ++i) {
        a[i] = 0xDEADBEEF; // A recognizable "garbage" hex value
    }
}

class Foo
{
private:
    int x {};       // default member initializer (will be ignored)
    int y { 42 };    // default member initializer (will be used)
    int z;      // no initializer, you see "0" in the output due to Compiler, 
                // not real initialzation value. It may contain garbage value
                // on other computers/compilers.

public:
    Foo(int x) 
        : x { x } // member initializer list
    {
        std::cout << "Foo constructed\n";
    }

    void print() const
    {
        std::cout << "Foo(" << x << ", " << y << ", " << z << ")\n";
    }
};

int main()
{
    do_dirty_stack();       // fill the stack with garbage first
    Foo foo { 6 };
    foo.print();

    return 0;
} // Compile with warning: g++ -Wall -Wextra -Wuninitialized different_initializers.cpp