#include <iostream>  // for std::cout and std::cin

int main()
{
    std::cout << "Enter two numbers: ";

    int x{};
    std::cin >> x;
    std::cout << "You entered " << x << '\n';
    int y{};
    std::cin >> y;
    std::cout << "You entered " << y << '\n';

    std::cout << "Finallay:";
    std::cout << "You entered " << x << " and " << y << '\n';
    return 0;
}