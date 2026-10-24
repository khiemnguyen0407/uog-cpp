#include <iostream>
#include <string_view>

class Base {
  public:
    virtual ~Base() = default;
    virtual std::string_view get_name() const { return "Base"; }
};
class Derived : public Base {
  public:
    std::string_view get_name() const override { return "Derived"; }
};

int main() {
    Derived derived{};
    Base& ref{derived}; // a reference: refers to the whole Derived
    Base copy{derived}; // a copy: only the Base part is copied!
    std::cout << "ref is a " << ref.get_name() << '\n';
    std::cout << "copy is a " << copy.get_name() << '\n';
    return 0;
}
