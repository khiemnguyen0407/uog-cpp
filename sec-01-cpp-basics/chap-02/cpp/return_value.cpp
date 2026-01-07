#include <iostream>

int get_value_from_user() // this function now returns an integer value
{
 	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input; // return the value the user entered back to the caller
}

int main()
{
	// initialize num with the return value of get_value_from_user()
	int num { get_value_from_user() }; 
	
	std::cout << num << " doubled is: " << num * 2 << '\n';

	return 0;
}