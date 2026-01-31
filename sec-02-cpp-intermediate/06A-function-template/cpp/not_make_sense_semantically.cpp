#include <iostream>

template <typename T>
T addOne(T x)
{
    return x + 1;
}

int main()
{
    std::cout << addOne("Hello, world!") << '\n';

    return 0;
}