#include <iostream>

class Display
{
private:
	bool display_int_first {};

public:
	Display(bool displayIntFirst)
		: display_int_first { displayIntFirst }
	{
	}

	void display_storage(const Storage& storage) // compile error: compiler doesn't know what a Storage is
	{
        /* This just does not work either.
		if (display_int_first)
			std::cout << storage.int_value << ' ' << storage.double_value << '\n';
		else // display double first
			std::cout << storage.double_value << ' ' << storage.int_value << '\n';
        */
	}
};

class Storage
{
private:
	int int_value {};
	double double_value {};
public:
	Storage(int int_value, double double_value)
		: int_value { int_value }, double_value { double_value }
	{
	}

	// Make the Display::display_storage member function a friend of the Storage class
	friend void Display::display_storage(const Storage& storage); // okay now
};

int main()
{
    Storage storage { 5, 6.7 };
    Display display { false };
    display.display_storage(storage);

    return 0;
}