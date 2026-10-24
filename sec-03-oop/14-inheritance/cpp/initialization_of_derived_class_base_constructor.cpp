#include <iostream>

class Base {
  public:
    const int id{}; // const is fine now
    Base(int id = 0) : id{id} {}
};

class Derived : public Base {
  public:
    double value{};
    Derived(double value = 0.0, int id = 0)
        : Base{id}, value{value} // call the Base constructor first
    {}
};

int main() {
    Derived derived{4.2, 42};
    std::cout << "id: " << derived.id << ", value: " << derived.value << '\n';
    return 0;
}
