#include <iostream>

template <typename T>
T max(T x, T y) // function template for max(T, T)
{
    return (x < y) ? y : x;
}
int main()
{
    std::cout << max<int>(1, 2) << '\n';    // instantiates and calls function max<int>(int, int)
    std::cout << max<int>(4, 3) << '\n';    // calls already instantiated function max<int>(int, int)
    std::cout << max<double>(1, 2) << '\n'; // instantiates and calls function max<double>(double, double)
    return 0;
}