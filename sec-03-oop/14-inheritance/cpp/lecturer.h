#ifndef LECTURER_H
#define LECTURER_H

#include "uniperson.h"
#include <string>

class Lecturer : public UniPerson { // a Lecturer IS a UniPerson
  private:
    double salary{}; // only what's new

  public:
    Lecturer(const std::string& name = "", int age = 0, double salary = 42000)
        : UniPerson{name, age}, salary{salary} {}

    double get_salary() const { return salary; }
};

#endif
