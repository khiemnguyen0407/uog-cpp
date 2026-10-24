#include <iostream>

class Accumulator {
  private:
    int value{};

  public:
    void add(int x) { value += x; }
    int get_value() const { return value; }
};

void print(const Accumulator& acc) { std::cout << acc.get_value() << '\n'; }

int main() {
    Accumulator acc{};
    acc.add(5);
    print(acc);
    return 0;
}
