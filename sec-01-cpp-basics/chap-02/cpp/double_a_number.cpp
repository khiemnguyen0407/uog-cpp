#include <iostream>

int get_value_from_user()
{
 	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input;
}

void print_double(int value) // This function now has an integer parameter
{
	std::cout << value << " doubled is: " << value * 2 << '\n';
}

int main()
{
	int num { get_value_from_user() };
	print_double(num);

    // We can also combine two statements into one.
    print_double(get_value_from_user());
	return 0;
}