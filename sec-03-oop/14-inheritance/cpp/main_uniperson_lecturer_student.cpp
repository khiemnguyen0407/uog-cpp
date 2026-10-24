#include "lecturer.h"
#include "student.h"
#include <iostream>

int main() {
    Lecturer khiem{"Khiem", 42, 55000};
    std::cout << khiem.get_name() << " (ID " << khiem.get_id() << "), salary "
              << khiem.get_salary() << '\n';

    Student peter{"Peter Parker", 18};
    std::cout << peter.get_name() << " (ID " << peter.get_id() << "), tuition "
              << peter.get_tuition() << '\n';
    return 0;
}
