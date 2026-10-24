#include "animals_nonvirtual.h"
#include <iostream>
#include <vector>

int main() {
    const Cat fred{"Fred"};
    const Cat misty{"Misty"};
    const Dog garbo{"Garbo"};
    const Dog pooky{"Pooky"};

    // One vector of Animal pointers holds cats AND dogs
    const std::vector<const Animal*> animals{&fred, &garbo, &misty, &pooky};

    for (const Animal* animal : animals) {
        std::cout << animal->get_name() << " says " << animal->speak() << '\n';
    }
    return 0;
}
