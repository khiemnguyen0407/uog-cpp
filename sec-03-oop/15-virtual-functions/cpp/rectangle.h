#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {
  private:
    double width{}, height{};

  public:
    Rectangle(double width, double height) : width{width}, height{height} {}
    double area() const override { return width * height; }
    std::string_view name() const override { return "rectangle"; }
};

#endif
