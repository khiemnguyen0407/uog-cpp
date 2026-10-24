#ifndef STUDENT_H
#define STUDENT_H

#include "uniperson.h"

class Student : public UniPerson {
  private:
    double tuition{};

  public:
    Student(const std::string& name = "", int age = 0, double tuition = 9250);
    double get_tuition() const;
};

#endif
