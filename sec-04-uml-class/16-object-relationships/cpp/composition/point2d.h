#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>

class Point2D {
  private:
    int x{};
    int y{};

  public:
    Point2D(int x = 0, int y = 0) : x{x}, y{y} {}

    void set(int new_x, int new_y) {
        x = new_x;
        y = new_y;
    }

    friend std::ostream& operator<<(std::ostream& out, const Point2D& p) {
        return out << '(' << p.x << ", " << p.y << ')';
    }
};

#endif
