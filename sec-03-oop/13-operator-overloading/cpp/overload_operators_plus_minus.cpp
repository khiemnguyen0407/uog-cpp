#include <iostream>

class Pennies {
  private:
    int pennies{};

  public:
    explicit Pennies(int pennies) : pennies{pennies} {}
    int get_pennies() const { return pennies; }

    friend Pennies operator+(const Pennies& a, const Pennies& b);
    friend Pennies operator-(const Pennies& a, const Pennies& b);
};
Pennies operator+(const Pennies& a, const Pennies& b) {
    return Pennies{a.pennies + b.pennies};
}
Pennies operator-(const Pennies& a, const Pennies& b) {
    return Pennies{a.pennies - b.pennies};
}

int main() {
    Pennies mine{42};
    Pennies yours{24};
    std::cout << "Together: " << (mine + yours).get_pennies() << '\n';
    std::cout << "Difference: " << (mine - yours).get_pennies() << '\n';
    return 0;
}
