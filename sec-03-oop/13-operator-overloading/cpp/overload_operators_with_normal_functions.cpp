#include <iostream>

class Pennies {
  private:
    int pennies{};

  public:
    explicit Pennies(int pennies) : pennies{pennies} {}
    int get_pennies() const { return pennies; } // public getter
};

// Neither a member nor a friend: the getter is all it needs
Pennies operator+(const Pennies& a, const Pennies& b) {
    return Pennies{a.get_pennies() + b.get_pennies()};
}

int main() {
    Pennies mine{42};
    Pennies yours{24};
    Pennies sum{mine + yours};
    std::cout << "I have " << sum.get_pennies() << " pennies.\n";
    return 0;
}
