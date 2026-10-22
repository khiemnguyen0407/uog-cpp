#include <iostream>

struct Employee {
    int id{};
    int age{42}; // a default member initializer
    double wage{};
};

int main() {
    Employee frank = {1, 32, 60000.0}; // copy-list initialization
    Employee joe{2, 28, 45000.0};      // list initialization (preferred)
    Employee khiem{};                  // every member gets its default

    std::cout << frank.wage << ' ' << joe.wage << '\n';
    std::cout << "khiem: " << khiem.age << ", " << khiem.wage << '\n';
    return 0;
}
