#include <iostream>

class Pennies {
  private:
    int pennies{};

  public:
    explicit Pennies(int pennies) : pennies{pennies} {}
    int get_pennies() const { return pennies; }

    friend Pennies operator+(const Pennies& a, const Pennies& b);
};

Pennies operator+(const Pennies& a, const Pennies& b) {
    return Pennies{a.pennies + b.pennies};
}

int main() {
    Pennies mine{42};
    std::cout << (mine + mine).get_pennies() << '\n';

    // Your turn: make these work too
    // std::cout << (42 + mine).get_pennies() << '\n';
    // std::cout << (mine + 42).get_pennies() << '\n';
    // std::cout << (3 * mine).get_pennies() << '\n';
    // std::cout << (mine * 3).get_pennies() << '\n';
    return 0;
}
