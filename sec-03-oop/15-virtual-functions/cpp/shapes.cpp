#include "circle.h"
#include "rectangle.h"
#include <iostream>
#include <memory> // std::unique_ptr (Chapter 09)
#include <vector>

int main() {
    std::vector<std::unique_ptr<Shape>> shapes{};
    shapes.push_back(std::make_unique<Circle>(1.0));
    shapes.push_back(std::make_unique<Rectangle>(2.0, 3.0));

    for (const auto& shape : shapes) { // one loop, every kind of shape
        std::cout << shape->name() << ": area " << shape->area() << '\n';
    }
    return 0;
} // the unique_ptrs delete the shapes, through ~Shape(): virtual!
