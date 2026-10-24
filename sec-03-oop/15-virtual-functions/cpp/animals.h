#ifndef ANIMALS_H
#define ANIMALS_H

#include <string>
#include <string_view>
class Animal {
  protected:
    std::string name{};
    Animal(std::string_view name) : name{name} {}

  public:
    virtual ~Animal() = default; // a virtual destructor: see later
    std::string_view get_name() const { return name; }
    virtual std::string_view speak() const { return "???"; } // virtual!
};
class Cat : public Animal {
  public:
    Cat(std::string_view name) : Animal{name} {}
    std::string_view speak() const override { return "Meow"; }
};
class Dog : public Animal {
  public:
    Dog(std::string_view name) : Animal{name} {}
    std::string_view speak() const override { return "Woof"; }
};
#endif
