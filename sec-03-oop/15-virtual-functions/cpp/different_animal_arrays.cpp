#include "animals_nonvirtual.h"
#include <iostream>

int main() {
    // Without a common type, every kind of animal needs its own array...
    const Cat cats[]{Cat{"Fred"}, Cat{"Misty"}, Cat{"Zeke"}};
    const Dog dogs[]{Dog{"Garbo"}, Dog{"Pooky"}, Dog{"Truffle"}};

    for (const auto& cat : cats) { // ...and its own loop
        std::cout << cat.get_name() << " says " << cat.speak() << '\n';
    }
    for (const auto& dog : dogs) {
        std::cout << dog.get_name() << " says " << dog.speak() << '\n';
    }
    return 0;
}
