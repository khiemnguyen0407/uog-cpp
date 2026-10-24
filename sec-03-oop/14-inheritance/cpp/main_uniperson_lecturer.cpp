#include "lecturer.h"
#include <iostream>

int main() {
    Lecturer khiem{"Khiem", 42};
    std::cout << khiem.get_name() << ", age " << khiem.get_age() << ", ID "
              << khiem.get_id() << '\n';

    Lecturer albus{"Albus", 115}; // a very experienced lecturer
    std::cout << albus.get_name() << ", age " << albus.get_age() << ", ID "
              << albus.get_id() << '\n';
    return 0;
}
