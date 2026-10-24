#include <iostream>

class IntBox { // owns one int on the heap
  private:
    int* data{};

  public:
    IntBox(int value) : data{new int{value}} {}
    ~IntBox() { delete data; }

    int get() const { return *data; }
};

int main() {
    IntBox a{42};
    IntBox b{a}; // copies the POINTER, not the int
    std::cout << a.get() << ' ' << b.get() << '\n';
    return 0;
} // b's destructor deletes the int... then a's deletes it again!
