#include "ugstudent.h"
#include <iostream>

// Default arguments go in the header only (Chapter 05)
UGStudent::UGStudent(const std::string& name, int age, double tuition)
    : Student{name, age, tuition} {}

void UGStudent::write_bsc_thesis() const {
    std::cout << get_name() << " (ID " << get_id()
              << ") is writing a BSc thesis\n";
}
