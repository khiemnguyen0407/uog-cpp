#include "animals_nonvirtual.h"
#include <iostream>

void report(const Animal& animal) { // works for any Animal...
    std::cout << animal.get_name() << " says " << animal.speak() << '\n';
}

int main() {
    report(Cat{"Felix"});
    report(Dog{"Rex"}); // ...but which speak() is called?
    return 0;
}
