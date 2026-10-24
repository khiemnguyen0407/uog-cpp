#include <iostream>

class Accumulator {
  private:
    double value{};

  public:
    void add(double x) { value += x; }

    // Defined inside the class, but still NOT a member function
    friend void print(const Accumulator& accumulator) {
        std::cout << accumulator.value << '\n';
    }
};

int main() {
    Accumulator acc{};
    acc.add(5);
    print(acc); // not acc.print()
    return 0;
}
