#include <string_view>
class A {
  public:
    virtual std::string_view get_name_1(int) const { return "A"; }
    virtual std::string_view get_name_2(int) const { return "A"; }
    virtual std::string_view get_name_3(int) const { return "A"; }
};
class B : public A {
  public:
    std::string_view get_name_1(short) const override { return "B"; } // error
    std::string_view get_name_2(int) override { return "B"; }         // error
    std::string_view get_name_3(int) const override { return "B"; }   // fine
};

int main() {
    B b{};
    return 0;
}
