#include "pennies.h"

Pennies operator+(const Pennies& a, const Pennies& b) {
    return Pennies{a.get_pennies() + b.get_pennies()};
}
