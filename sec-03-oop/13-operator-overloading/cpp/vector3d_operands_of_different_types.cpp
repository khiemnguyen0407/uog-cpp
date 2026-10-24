#include <iostream>

class Vector3D {
  private:
    double x{}, y{}, z{};

  public:
    Vector3D(double x, double y, double z) : x{x}, y{y}, z{z} {}

    friend Vector3D operator+(double s, const Vector3D& v) { // s + v
        return Vector3D{s + v.x, s + v.y, s + v.z};
    }
    friend Vector3D operator+(const Vector3D& v, double s) { // v + s
        return s + v; // reuse the version above
    }

    void print() const {
        std::cout << "(" << x << ", " << y << ", " << z << ")\n";
    }
};

int main() {
    Vector3D w{1, 2, 3};
    (42 + w).print();
    (w + 42).print();
    return 0;
}
