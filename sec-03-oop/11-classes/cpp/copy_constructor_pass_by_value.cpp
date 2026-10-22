#include "fraction.h"

void print_fraction(Fraction f) { // f is passed by value
    f.print();
}

int main() {
    Fraction f{5, 3};
    print_fraction(f); // f is copied into the parameter
    return 0;
}
