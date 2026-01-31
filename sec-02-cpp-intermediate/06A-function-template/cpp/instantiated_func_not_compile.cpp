#include <iostream>
#include <string>

template <typename T>
T add_value(T x, double v)
{
    return x + v;
}

int main()
{
    std::cout << add_value(4.2, 2.4) << '\n';   // This make sense.
    std::string hello { "Hello, world!" };
    // This won't make sense: string + double!?!?
    std::cout << add_value(hello, 4.2) << '\n';  // compile error 

    return 0;
}