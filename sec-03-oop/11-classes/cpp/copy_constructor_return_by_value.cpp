#include "fraction.h"

void print_fraction(Fraction f) { f.print(); } // a copy each time

Fraction make_fraction(int n, int d) {
    Fraction f{n, d};
    return f; // a copy here too? (spoiler: no)
}

int main() {
    Fraction f1{};
    print_fraction(f1);
    Fraction f2{make_fraction(1, 2)};
    print_fraction(f2);
    Fraction f3{make_fraction(4, 2)};
    print_fraction(f3);
    return 0;
}
