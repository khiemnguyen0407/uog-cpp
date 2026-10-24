#ifndef BASE_DERIVED_H
#define BASE_DERIVED_H

#include <string_view>

class Base {
  protected:
    int id{};

  public:
    Base(int id) : id{id} {}
    std::string_view get_name() const { return "Base"; } // NOT virtual
};

class Derived : public Base {
  private:
    double value{};

  public:
    Derived(double value, int id) : Base{id}, value{value} {}
    std::string_view get_name() const { return "Derived"; }
    double get_value() const { return value; }
};

#endif
