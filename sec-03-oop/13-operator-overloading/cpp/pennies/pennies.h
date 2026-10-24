#ifndef PENNIES_H
#define PENNIES_H

class Pennies {
  private:
    int pennies{};

  public:
    explicit Pennies(int pennies) : pennies{pennies} {}
    int get_pennies() const { return pennies; }
};

// A normal function: other files only know it exists from this declaration
Pennies operator+(const Pennies& a, const Pennies& b);

#endif
