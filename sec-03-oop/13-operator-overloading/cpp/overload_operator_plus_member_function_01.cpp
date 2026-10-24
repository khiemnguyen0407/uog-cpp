#include <iostream>

class Pennies {
  private:
    int pennies{};

  public:
    explicit Pennies(int pennies) : pennies{pennies} {}
    int get_pennies() const { return pennies; }

    Pennies operator+(const Pennies& other) const; // a member now
};

// Defined outside the class: note the Pennies:: in front of the name
Pennies Pennies::operator+(const Pennies& other) const {
    return Pennies{pennies + other.pennies}; // pennies is this->pennies
}

int main() {
    Pennies mine{42};
    Pennies yours{12};
    Pennies sum{mine + yours}; // mine.operator+(yours)
    std::cout << "I have " << sum.get_pennies() << " pennies.\n";
    return 0;
}
