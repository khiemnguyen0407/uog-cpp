#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <vector>

class Doctor; // forward declaration: Patient refers to Doctor

class Patient {
  private:
    std::string name{};
    std::vector<const Doctor*> doctors{}; // a patient knows their doctors

  public:
    Patient(const std::string& name) : name{name} {}
    const std::string& get_name() const { return name; }
    const std::vector<const Doctor*>& get_doctors() const { return doctors; }
    void add_doctor(const Doctor& doctor) { doctors.push_back(&doctor); }
};

#endif
