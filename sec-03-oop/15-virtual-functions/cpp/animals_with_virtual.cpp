#include "animals.h" // the same classes, with a virtual speak()
#include <iostream>
#include <vector>

void report(const Animal& animal) {
    std::cout << animal.get_name() << " says " << animal.speak() << '\n';
}

int main() {
    report(Cat{"Felix"});
    report(Dog{"Rex"});

    const Cat fred{"Fred"};
    const Dog garbo{"Garbo"};
    const std::vector<const Animal*> animals{&fred, &garbo};
    for (const Animal* animal : animals) {
        report(*animal);
    }
    return 0;
}
