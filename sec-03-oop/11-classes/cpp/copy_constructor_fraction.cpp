#include "fraction.h"

int main() {
    Fraction f{5, 3};
    Fraction f_copy{f}; // calls Fraction(const Fraction&)
    f_copy.print();
    return 0;
}
