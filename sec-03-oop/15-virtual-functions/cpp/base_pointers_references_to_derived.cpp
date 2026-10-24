#include "base_derived.h"
#include <iostream>

int main() {
    Derived derived{42.24, 42};
    Base& base_ref{derived};  // a Base reference to a Derived object
    Base* base_ptr{&derived}; // a Base pointer to a Derived object
    std::cout << derived.get_name() << '\n';
    std::cout << base_ref.get_name() << '\n';  // which get_name()?
    std::cout << base_ptr->get_name() << '\n'; // which get_name()?
    // base_ref.get_value(); // error: a Base has no get_value()
    return 0;
}
