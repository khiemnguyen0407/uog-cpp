#include <iostream>

struct Employee {
    int id{};
    int age{};
    double wage{};
};

int main() {
    Employee khiem{1, 42, 4.2e20};
    Employee* ptr{&khiem};
    std::cout << ptr.id << '\n'; // error: ptr is a pointer
    return 0;
}
