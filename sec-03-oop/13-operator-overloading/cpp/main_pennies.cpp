#include "pennies/pennies.h" // the header is in the folder pennies/
#include <iostream>

int main() {
    Pennies mine{42};
    Pennies yours{24};
    Pennies sum{mine + yours};
    std::cout << "I have " << sum.get_pennies() << " pennies.\n";
    return 0;
}
