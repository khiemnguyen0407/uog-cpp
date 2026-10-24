#include <iostream>

class Accumulator {
  private:
    int value{};

  public:
    void add(int x) { value += x; }
    friend void print(const Accumulator& acc);
};

void print(const Accumulator& acc) { std::cout << acc.value << '\n'; }

int main() {
    Accumulator acc{};
    acc.add(5);
    print(acc);
    return 0;
}
