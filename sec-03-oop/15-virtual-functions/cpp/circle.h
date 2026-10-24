#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <numbers> // std::numbers::pi (Chapter 04)

class Circle : public Shape {
  private:
    double radius{};

  public:
    Circle(double radius) : radius{radius} {}
    double area() const override { return std::numbers::pi * radius * radius; }
    std::string_view name() const override { return "circle"; }
};

#endif
