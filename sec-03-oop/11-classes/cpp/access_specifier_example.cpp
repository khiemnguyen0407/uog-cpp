#include <iostream>

class Date {
  public:                // everything below is public...
    void print() const { // members may use private members
        std::cout << year << '/' << month << '/' << day << '\n';
    }

  private: // ...and everything below is private
    int year{2026};
    int month{2};
    int day{26};
};

int main() {
    Date today{};
    today.print(); // fine: print() is public
    return 0;
}
