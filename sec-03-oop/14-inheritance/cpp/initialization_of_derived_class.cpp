class Base {
  public:
    int id{};
    Base(int id = 0) : id{id} {}
};

class Derived : public Base {
  public:
    double value{};
    Derived(double value = 0.0) : value{value} {} // and id?
};

int main() {
    Base base{42};        // Base(int): sets id
    Derived derived{4.2}; // Derived(double): sets value... but id?
    return 0;
}
