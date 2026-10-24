#include <iostream>

class Base {
  private:
    int id{};

  public:
    Base(int id) : id{id} {}

  protected:
    void print_id() const { std::cout << "ID " << id << '\n'; }
};

class Derived : public Base {
  public:
    Derived(int id) : Base{id} {}
    using Base::print_id; // protected in Base, public in Derived
};

int main() {
    Derived d{42};
    d.print_id(); // fine now
    return 0;
}
