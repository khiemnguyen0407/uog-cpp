#ifndef ANIMALS_NONVIRTUAL_H
#define ANIMALS_NONVIRTUAL_H

#include <string>
#include <string_view>
class Animal {
  protected:
    std::string name{};
    Animal(std::string_view name) : name{name} {}

  public:
    std::string_view get_name() const { return name; }
    std::string_view speak() const { return "???"; }
};
class Cat : public Animal {
  public:
    Cat(std::string_view name) : Animal{name} {}
    std::string_view speak() const { return "Meow"; }
};
class Dog : public Animal {
  public:
    Dog(std::string_view name) : Animal{name} {}
    std::string_view speak() const { return "Woof"; }
};
#endif
