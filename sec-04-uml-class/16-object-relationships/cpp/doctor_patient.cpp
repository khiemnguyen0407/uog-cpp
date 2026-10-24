#include "doctor.h"
#include <iostream>

int main() {
    Patient dave{"Dave"}; // patients and doctors exist independently
    Patient betsy{"Betsy"};
    Doctor james{"James"};
    Doctor sarah{"Sarah"};

    james.add_patient(dave);
    sarah.add_patient(dave); // Dave sees two doctors...
    sarah.add_patient(betsy);

    std::cout << "Sarah sees:";
    for (const Patient* patient : sarah.get_patients()) {
        std::cout << ' ' << patient->get_name(); // ...Sarah sees two patients
    }
    std::cout << "\nDave sees:";
    for (const Doctor* doctor : dave.get_doctors()) {
        std::cout << ' ' << doctor->get_name();
    }
    std::cout << '\n';
    return 0;
}
