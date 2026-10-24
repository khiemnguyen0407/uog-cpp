#include "lecturer.h"

Lecturer::Lecturer(const std::string& name, int age, double salary)
    : UniPerson{name, age}, salary{salary} {}

double Lecturer::get_salary() const { return salary; }
