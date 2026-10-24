#include <iostream>

class Pennies {
  private:
    int pennies{};

  public:
    explicit Pennies(int pennies) : pennies{pennies} {}
    int get_pennies() const { return pennies; }

    friend Pennies operator+(const Pennies& a, const Pennies& b);
};

Pennies operator+(const Pennies& a, const Pennies& b) { // a friend
    return Pennies{a.pennies + b.pennies};
}

int main() {
    Pennies mine{42};
    Pennies yours{12};
    Pennies sum{mine + yours}; // operator+(mine, yours)
    std::cout << "I have " << sum.get_pennies() << " pennies.\n";
    return 0;
}
