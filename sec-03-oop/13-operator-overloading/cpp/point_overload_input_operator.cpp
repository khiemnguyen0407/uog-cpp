#include <iostream>

class Point {
  private:
    double x{}, y{}, z{};

  public:
    friend std::ostream& operator<<(std::ostream& out, const Point& p);
    friend std::istream& operator>>(std::istream& in, Point& p);
};

std::ostream& operator<<(std::ostream& out, const Point& p) {
    out << "Point(" << p.x << ", " << p.y << ", " << p.z << ')';
    return out;
}
std::istream& operator>>(std::istream& in, Point& p) { // p is NOT const
    in >> p.x >> p.y >> p.z;
    return in;
}

int main() {
    std::cout << "Enter a point: ";
    Point point{};
    std::cin >> point;
    std::cout << "You entered " << point << '\n';
    return 0;
}
