#include <iostream>
#include <typeinfo>

int main()
{
	int* x { nullptr };
	std::cout << typeid(x).name() << '\n';  // print the type of x
	std::cout << typeid(&x).name() << '\n'; // print the type of &x

	return 0;
}