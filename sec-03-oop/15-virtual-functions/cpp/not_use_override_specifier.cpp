#include <iostream>
#include <string_view>

class A {
  public:
    virtual std::string_view get_name_1(int) const { return "A"; }
    virtual std::string_view get_name_2(int) const { return "A"; }
};
class B : public A {
  public:
    // Look closely: neither of these overrides anything!
    virtual std::string_view get_name_1(short) const { return "B"; }
    virtual std::string_view get_name_2(int) { return "B"; } // not const
};

int main() {
    B b{};
    A& base_ref{b};
    std::cout << base_ref.get_name_1(1) << '\n';
    std::cout << base_ref.get_name_2(2) << '\n';
    return 0;
}
