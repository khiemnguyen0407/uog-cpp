#include <string_view>
class A {
  public:
    virtual std::string_view get_name() const { return "A"; }
};
class B : public A {
  public:
    std::string_view get_name() const override final { return "B"; }
};
class C : public B {
  public:
    std::string_view get_name() const override { return "C"; } // error
};

int main() {
    C c{};
    return 0;
}
