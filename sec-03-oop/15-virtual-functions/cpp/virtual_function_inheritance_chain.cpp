#include <iostream>
#include <string_view>

class A {
  public:
    virtual std::string_view get_name() const { return "A"; }
};
class B : public A {
  public:
    std::string_view get_name() const override { return "B"; }
};
class C : public B {
  public:
    std::string_view get_name() const override { return "C"; }
};
class D : public C {
  public:
    std::string_view get_name() const override { return "D"; }
};

int main() {
    C c{};
    A& base_ref{c};
    std::cout << "base_ref is a " << base_ref.get_name() << '\n';
    return 0;
}
