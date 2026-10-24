class Pennies {
  private:
    int pennies{};

  public:
    explicit Pennies(int pennies) : pennies{pennies} {}
    int get_pennies() const { return pennies; }
};
