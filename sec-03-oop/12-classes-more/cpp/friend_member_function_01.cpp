#include <iostream>

class Display; // only a forward declaration

class Storage {
  private:
    int int_value{};
    double double_value{};

  public:
    Storage(int i, double d) : int_value{i}, double_value{d} {}
    friend void Display::show(const Storage& s) const; // error!
};

class Display {
  public:
    void show(const Storage& s) const {
        std::cout << s.int_value << ' ' << s.double_value << '\n';
    }
};

int main() {
    Display{}.show(Storage{5, 6.7});
    return 0;
}
