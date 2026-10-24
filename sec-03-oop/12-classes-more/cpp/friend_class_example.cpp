#include <iostream>

class Storage {
  private:
    int int_value{};
    double double_value{};

  public:
    Storage(int i, double d) : int_value{i}, double_value{d} {}
    friend class Display; // Display may use our private members
};

class Display {
  public:
    void show(const Storage& s) const { // allowed: Display is a friend
        std::cout << s.int_value << ' ' << s.double_value << '\n';
    }
};

int main() {
    Storage storage{5, 6.7};
    Display display{};
    display.show(storage);
    return 0;
}
