#include <iostream>

class Date { // we changed struct to class...
  public:    // ...and added this access specifier
    int day{};
    int month{};
    int year{};
};

void print_date(const Date& date) {
    std::cout << date.day << '/' << date.month << '/' << date.year << '\n';
}

int main() {
    Date date{26, 2, 2026};
    print_date(date);
    return 0;
}
