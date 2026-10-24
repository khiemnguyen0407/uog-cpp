class Base {
  public:
    const int id{}; // a const member: try removing const
    Base(int id = 0) : id{id} {}
};

class Derived : public Base {
  public:
    double value{};
    Derived(double value = 0.0, int id = 0) : value{value} {
        this->id = id; // error: assigning to a const member
    }
};

int main() {
    Derived derived{4.2, 42};
    return 0;
}
