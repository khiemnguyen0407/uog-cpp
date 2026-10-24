#include <iostream>

class Point {
  private:
    double x{}, y{}, z{};

  public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0) : x{x}, y{y}, z{z} {}

    void print() const {
        std::cout << "Point(" << x << ", " << y << ", " << z << ')';
    }
};

int main() {
    const Point point{42.0, 24.0, 12.0};
    std::cout << "My point is ";
    point.print(); // breaks the statement up
    std::cout << " in Cartesian space.\n";
    return 0;
}
