class Base {
  public:
    int value{};
};

class Derived : public Base {
  private:
    using Base::value; // public in Base, private in Derived
};

int main() {
    Base b{};
    b.value = 1; // fine
    Derived d{};
    d.value = 2; // error: value is private in Derived
    return 0;
}
