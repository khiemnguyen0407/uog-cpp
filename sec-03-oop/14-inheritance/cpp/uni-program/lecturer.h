#ifndef LECTURER_H
#define LECTURER_H

#include "uniperson.h"

class Lecturer : public UniPerson {
  private:
    double salary{};

  public:
    Lecturer(const std::string& name = "", int age = 0, double salary = 42000);
    double get_salary() const;
};

#endif
