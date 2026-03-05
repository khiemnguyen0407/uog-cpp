// C++ program to illustrate return by reference
#include <iostream>

// Function to return as return by reference
int& return_by_ref(int& x)
{

    // Print the address
    std::cout << "x = " << x << " The address of x is " << &x << '\n';

    // Return reference
    return x;
}

int main()
{
    int a = 20;
    int& b = return_by_ref(a);

    // Print a and its address
    std::cout << "a = " << a << " The address of a is " << &a << '\n';
    // Print b and its address
    std::cout << "b = " << b << " The address of b is " << &b << '\n';

    // We can also change the value of
    // 'a' by using the address returned
    // by return_by_ref function

    // Since the function returns an alias
    // of x, which is itself an alias of a,
    // we can update the value of a
    return_by_ref(a) = 13;

    // The above expression assigns the
    // value to the returned alias as 3.
    std::cout << "a = " << a << " The address of a is " << &a << '\n';
    return 0;
}