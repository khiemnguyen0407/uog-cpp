#include "animals_nonvirtual.h"
#include <iostream>

int main() {
    const Cat cat{"Felix"};
    const Dog dog{"Rex"};
    std::cout << cat.get_name() << " says " << cat.speak() << '\n';
    std::cout << dog.get_name() << " says " << dog.speak() << '\n';

    const Animal* animal{&cat}; // an Animal pointer to a Cat
    std::cout << animal->get_name() << " says " << animal->speak() << '\n';

    animal = &dog; // now to a Dog
    std::cout << animal->get_name() << " says " << animal->speak() << '\n';
    return 0;
}
