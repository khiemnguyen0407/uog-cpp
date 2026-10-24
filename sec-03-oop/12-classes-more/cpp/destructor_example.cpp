#include <iostream>

class Simple {
  private:
    int id{};

  public:
    Simple(int id) : id{id} { std::cout << "Constructing " << id << '\n'; }
    ~Simple() { std::cout << "Destructing " << id << '\n'; } // destructor
};

int main() {
    Simple simple1{1};
    {
        Simple simple2{2};
    } // simple2 is destroyed here
    Simple simple3{3};
    return 0;
} // simple3, then simple1, are destroyed here
