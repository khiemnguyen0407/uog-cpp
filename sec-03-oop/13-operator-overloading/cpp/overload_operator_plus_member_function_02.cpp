#include <iostream>

class Pennies {
  private:
    int pennies{};

  public:
    explicit Pennies(int pennies) : pennies{pennies} {}

    Pennies operator+(int value) const { // a member: Pennies + int
        return Pennies{pennies + value};
    }

    // Must be a non-member: the left operand is a std::ostream
    friend std::ostream& operator<<(std::ostream& out, const Pennies& p) {
        return out << p.pennies << " pennies"; // << returns out
    }
};

int main() {
    Pennies mine{42};
    std::cout << "I have " << (mine + 12) << ".\n";
    return 0;
}
