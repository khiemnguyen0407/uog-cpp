#include <iostream>

class Accumulator {
  private:
    double value{};

  public:
    void add(double x) { value += x; }

    // print() is not a member, but it may use our private members
    friend void print(const Accumulator& accumulator);
};

void print(const Accumulator& accumulator) { // not a member!
    std::cout << accumulator.value << '\n';  // allowed: it's a friend
}

int main() {
    Accumulator acc{};
    acc.add(42);
    print(acc); // called like any non-member function
    return 0;
}
