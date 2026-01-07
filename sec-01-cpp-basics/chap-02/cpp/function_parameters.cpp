// This function takes no parameters
// It does not rely on the caller for anything
void say_hello()
{
    std::cout << "Hello World\n";
}
// This function takes one integer parameter named x
// The caller will supply the value of x
void print_value(double x)
{
    std::cout << x << '\n';
}
// This function has two integer parameters, one named x, and one named y
// The caller will supply the value of both x and y
int add(double x, double y)
{
    return x + y;
}
/* This code snippet cannot be compiled. */