#ifndef DOCTOR_H
#define DOCTOR_H

#include "patient.h"
#include <string>
#include <vector>

class Doctor {
  private:
    std::string name{};
    std::vector<const Patient*> patients{}; // a doctor knows their patients

  public:
    Doctor(const std::string& name) : name{name} {}
    const std::string& get_name() const { return name; }
    const std::vector<const Patient*>& get_patients() const { return patients; }

    void add_patient(Patient& patient) {
        patients.push_back(&patient);
        patient.add_doctor(*this); // keep both sides of the link in sync
    }
};

#endif
