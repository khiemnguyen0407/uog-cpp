#include <iostream>

template <typename T>
void print(T val, int times=1)
{
    std::cout << "Start printing:\n";
    for (size_t i {0}; i < times; i++)
        std::cout << "\t# " << i + 1 << ": value = " << val << '\n';
}

int main()
{
    print(5);      // print 5 1 time
    print('a', 3); // print 'a' 3 times

    return 0;
}