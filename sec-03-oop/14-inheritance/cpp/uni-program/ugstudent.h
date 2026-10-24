#ifndef UGSTUDENT_H
#define UGSTUDENT_H

#include "student.h"

class UGStudent : public Student { // a chain: UniPerson <- Student <- UGStudent
  public:
    UGStudent(const std::string& name = "", int age = 0, double tuition = 9250);
    void write_bsc_thesis() const;
};

#endif
