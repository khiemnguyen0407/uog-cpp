class Base {
  public:
    int id{};

    Base(int id = 0) : id{id} {}
    int get_id() const { return id; }
};

class Derived : public Base { // Derived inherits id and get_id()
  public:
    double value{};

    Derived(double value = 0.0) : value{value} {}
    double get_value() const { return value; }
};

int main() {
    Base base{42};
    Derived derived{42.24};
    return 0;
}
