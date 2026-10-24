#include "base_derived.h"
#include <iostream>

int main() {
    Derived derived{42.24, 42};
    Derived& ref{derived};
    Derived* ptr{&derived};
    std::cout << derived.get_name() << ' ' << derived.get_value() << '\n';
    std::cout << ref.get_name() << ' ' << ref.get_value() << '\n';
    std::cout << ptr->get_name() << ' ' << ptr->get_value() << '\n';
    return 0;
}
