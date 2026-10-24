#include <iostream>

class Point {
  private:
    double x{}, y{}, z{};

  public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0) : x{x}, y{y}, z{z} {}

    // Point depends on std::ostream: it USES one, but doesn't keep one
    friend std::ostream& operator<<(std::ostream& out, const Point& p) {
        return out << "Point(" << p.x << ", " << p.y << ", " << p.z << ')';
    }
};

int main() {
    Point p{42.0, 24.0, 42.24};
    std::cout << p << '\n';
    return 0;
}
