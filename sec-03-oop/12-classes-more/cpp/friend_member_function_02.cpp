#include <iostream>

class Display {
  public:
    void show(const Storage& s) const { // error: what is a Storage?
        std::cout << s.int_value << ' ' << s.double_value << '\n';
    }
};

class Storage {
  private:
    int int_value{};
    double double_value{};

  public:
    Storage(int i, double d) : int_value{i}, double_value{d} {}
    friend void Display::show(const Storage& s) const;
};

int main() {
    Display{}.show(Storage{5, 6.7});
    return 0;
}
