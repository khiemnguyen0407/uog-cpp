#include <iostream>

int main()
{
	int x{};
	std::cout << "Enter an integer: ";
	std::cin >> x;
	int y{};
	std::cout << "Enter an integer: ";
	std::cin >> y;
	std::cout << x << " + " << y << " = " << x + y << '\n';

	return 0;
}