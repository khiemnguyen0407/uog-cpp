class Base {
  public:
    int public_member{}; // anyone
  protected:
    int protected_member{}; // Base, its friends, derived classes
  private:
    int private_member{}; // Base and its friends only
};

class Derived : public Base {
  public:
    Derived() {
        public_member = 1;    // fine
        protected_member = 2; // fine: Derived is a derived class
        private_member = 3;   // error: private to Base
    }
};

int main() {
    Base base{};
    base.public_member = 1;    // fine
    base.protected_member = 2; // error: main() is "the public"
    return 0;
}
