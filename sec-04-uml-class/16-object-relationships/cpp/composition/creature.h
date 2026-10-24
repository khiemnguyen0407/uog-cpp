#ifndef CREATURE_H
#define CREATURE_H

#include "point2d.h"
#include <iostream>
#include <string>

class Creature {
  private:
    std::string name{};
    Point2D location{}; // composition: a part of every Creature

  public:
    Creature(const std::string& name, const Point2D& location)
        : name{name}, location{location} {}

    void move_to(int x, int y) { location.set(x, y); }

    friend std::ostream& operator<<(std::ostream& out, const Creature& c) {
        return out << c.name << " is at " << c.location;
    }
};

#endif
