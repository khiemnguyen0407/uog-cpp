#include "pennies.h"
#include <iostream>

int main() {
    Pennies mine{42};
    Pennies yours{24};
    Pennies sum{mine + yours}; // needs the declaration in pennies.h
    std::cout << "I have " << sum.get_pennies() << " pennies.\n";
    return 0;
}
