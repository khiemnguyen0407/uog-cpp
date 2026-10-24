class Base {
  public:
    virtual int get_value() const { return 5; }
};
class Derived : public Base {
  public:
    double get_value() const { return 6.78; } // error: different return type
};

int main() {
    Derived derived{};
    return 0;
}
