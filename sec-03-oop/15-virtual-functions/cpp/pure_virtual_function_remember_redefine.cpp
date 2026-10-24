#include <iostream>
#include <string>
#include <string_view>

class Animal { // an abstract base class
  protected:
    std::string name{};
    Animal(std::string_view name) : name{name} {}

  public:
    virtual ~Animal() = default;
    std::string_view get_name() const { return name; }
    virtual std::string_view speak() const = 0; // pure virtual
};
class Cow : public Animal {
  public:
    Cow(std::string_view name) : Animal{name} {}
    std::string_view speak() const override { return "Moo"; } // now we must
};

int main() {
    Cow cow{"Betsy"};
    std::cout << cow.get_name() << " says " << cow.speak() << '\n';
    return 0;
}
