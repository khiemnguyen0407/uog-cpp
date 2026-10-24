#include <iostream>

class Pennies {
  private:
    int pennies{};

  public:
    explicit Pennies(int pennies) : pennies{pennies} {}
    int get_pennies() const { return pennies; }

    // Defined inside the class, but still a non-member function
    friend Pennies operator+(const Pennies& a, const Pennies& b) {
        return Pennies{a.pennies + b.pennies};
    }
};

int main() {
    Pennies mine{42};
    Pennies yours{24};
    Pennies sum{mine + yours};
    std::cout << "I have " << sum.get_pennies() << " pennies.\n";
    return 0;
}
