#include <iostream>

class Vector2D {
  private:
    double x{}, y{};

  public:
    Vector2D(double new_x, double new_y) { // a constructor
        x = new_x;
        y = new_y;
        std::cout << "Vector2D(" << x << ", " << y << ") constructed\n";
    }

    void print() const { std::cout << "(" << x << ", " << y << ")\n"; }
};

int main() {
    Vector2D v{4.2, 2.4}; // calls Vector2D(double, double)
    v.print();
    return 0;
}
