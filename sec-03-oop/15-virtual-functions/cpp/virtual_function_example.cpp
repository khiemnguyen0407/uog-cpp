#include <iostream>
#include <string_view>

class Base {
  public:
    virtual std::string_view get_name() const { return "Base"; } // virtual!
};
class Derived : public Base {
  public:
    std::string_view get_name() const override { return "Derived"; }
};

int main() {
    Derived derived{};
    Base& base_ref{derived};
    std::cout << "base_ref is a " << base_ref.get_name() << '\n';
    return 0;
}
