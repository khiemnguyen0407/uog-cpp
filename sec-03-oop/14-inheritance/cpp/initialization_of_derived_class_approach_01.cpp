class Base {
  public:
    int id{};
    Base(int id = 0) : id{id} {}
};

class Derived : public Base {
  public:
    double value{};
    Derived(double value = 0.0, int id = 0)
        : value{value}, id{id} // error: id is not Derived's own member
    {}
};

int main() {
    Derived derived{4.2, 42};
    return 0;
}
