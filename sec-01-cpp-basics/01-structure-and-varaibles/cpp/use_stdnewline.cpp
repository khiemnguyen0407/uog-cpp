#include <iostream> // for std::cout and std::endl

int main()
{
    // std::endl will cause the cursor to move to the next line
    std::cout << "Hi!\n";                // try to remove std::endl here
    std::cout << "My name is Alex." << std::endl;   // try to remove std::endl here

    // However, it is advisable to use:
    std::cout << "Hi!\n" << "My name is Khiem." << '\n';    // \n add a new line too
    return 0;
}