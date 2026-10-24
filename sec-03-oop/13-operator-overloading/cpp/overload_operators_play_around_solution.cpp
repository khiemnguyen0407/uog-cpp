#include <iostream>

class Pennies {
  private:
    int pennies{};

  public:
    explicit Pennies(int pennies) : pennies{pennies} {}
    int get_pennies() const { return pennies; }

    friend Pennies operator+(const Pennies& a, const Pennies& b);
    friend Pennies operator+(int value, const Pennies& p);
    friend Pennies operator*(int factor, const Pennies& p);
};

Pennies operator+(const Pennies& a, const Pennies& b) {
    return Pennies{a.pennies + b.pennies};
}

Pennies operator+(int value, const Pennies& p) {
    return Pennies{value + p.pennies};
}

Pennies operator+(const Pennies& p, int value) { // no friendship needed:
    return value + p;                            // it reuses the one above
}

Pennies operator*(int factor, const Pennies& p) {
    return Pennies{factor * p.pennies};
}

Pennies operator*(const Pennies& p, int factor) { return factor * p; }

int main() {
    Pennies mine{42};
    std::cout << (42 + mine).get_pennies() << '\n';
    std::cout << (mine + 42).get_pennies() << '\n';
    std::cout << (3 * mine).get_pennies() << '\n';
    std::cout << (mine * 3).get_pennies() << '\n';
    return 0;
}
