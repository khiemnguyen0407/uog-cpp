#ifndef BASE_DERIVED_H
#define BASE_DERIVED_H

#include <iostream>

class Base {
  protected:
    int id{};

  public:
    Base(int id = 0) : id{id} {}
    void identify() const { std::cout << "I am a Base, ID " << id << '\n'; }
};

class Derived : public Base {
  private:
    double value{}; // new in Derived

  public:
    Derived(double value = 0.0, int id = 0) : Base{id}, value{value} {}
    void print() const { // new in Derived
        std::cout << "ID " << id << ", value " << value << '\n';
    }
};

#endif
