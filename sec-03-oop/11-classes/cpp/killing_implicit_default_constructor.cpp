class Foo {

private:
    int x {};
    int y {};
public:
    Foo(int x, int y) : x{x}, y {} {}  // This "kills" the implicit default constructor
};

int main()
{   
    Foo foo1 { 1, 2 };  // Fine. the compiler uses Foo(int, int) to construct the object.
    // Foo foo2 {};    // error: there is no default constructor
}