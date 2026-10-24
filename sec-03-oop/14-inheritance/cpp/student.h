#ifndef STUDENT_H
#define STUDENT_H

#include "uniperson.h"
#include <string>

class Student : public UniPerson { // a Student IS a UniPerson
  private:
    double tuition{};

  public:
    Student(const std::string& name = "", int age = 0, double tuition = 9250)
        : UniPerson{name, age}, tuition{tuition} {}

    double get_tuition() const { return tuition; }
};

#endif
