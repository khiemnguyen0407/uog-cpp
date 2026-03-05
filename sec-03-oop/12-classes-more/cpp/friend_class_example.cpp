#include <iostream>

class Storage
{
private:
    int int_value {};
    double double_value {};
public:
    Storage(int int_value, double double_value)
       : int_value { int_value }, double_value { double_value } { }

    // Make the Display class a friend of Storage
    friend class Display;
};

class Display
{
private:
    bool display_int_first {};

public:
    Display(bool display_int_first)
         : display_int_first { display_int_first } { }

    // Because Display is a friend of Storage, Display members can access the private members of Storage
    void display_storage(const Storage& storage) {
        if (display_int_first)
            std::cout << storage.int_value << ' ' << storage.double_value << '\n';
        else // display double first
            std::cout << storage.double_value << ' ' << storage.int_value << '\n';
    }

    void set_display_int_first(bool b) {
         display_int_first = b;
    }
};

int main()
{
    Storage storage { 5, 6.7 };
    Display display { false };
    display.display_storage(storage);
    display.set_display_int_first(true);
    display.display_storage(storage);

    return 0;
}