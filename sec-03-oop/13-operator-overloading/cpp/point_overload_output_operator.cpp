#include <iostream>

class Point {
  private:
    double x{}, y{}, z{};

  public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0) : x{x}, y{y}, z{z} {}

    friend std::ostream& operator<<(std::ostream& out, const Point& p);
};

std::ostream& operator<<(std::ostream& out, const Point& p) {
    out << "Point(" << p.x << ", " << p.y << ", " << p.z << ')';
    return out; // return the stream, so that << can be chained
}

int main() {
    const Point p1{42.0, 24.0, 12.0};
    const Point p2{1.0, 2.0, 3.0};
    std::cout << "My points are " << p1 << " and " << p2 << '\n';
    return 0;
}
