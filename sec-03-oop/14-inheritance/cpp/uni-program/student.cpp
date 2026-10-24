#include "student.h"

Student::Student(const std::string& name, int age, double tuition)
    : UniPerson{name, age}, tuition{tuition} {}

double Student::get_tuition() const { return tuition; }
