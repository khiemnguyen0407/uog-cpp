#include <iostream>

class Storage; // 1. a forward declaration of Storage

class Display {
  public:
    void show(const Storage& s) const; // 2. declared, not defined yet
};

class Storage {
  private:
    int int_value{};
    double double_value{};

  public:
    Storage(int i, double d) : int_value{i}, double_value{d} {}
    friend void Display::show(const Storage& s) const; // fine now
};

void Display::show(const Storage& s) const { // 3. defined after Storage
    std::cout << s.int_value << ' ' << s.double_value << '\n';
}

int main() {
    Display{}.show(Storage{5, 6.7});
    return 0;
}
