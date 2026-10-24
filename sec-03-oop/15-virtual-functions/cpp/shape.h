#ifndef SHAPE_H
#define SHAPE_H

#include <string_view>

class Shape { // an abstract base class: what every shape must provide
  public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
    virtual std::string_view name() const = 0;
};

#endif
