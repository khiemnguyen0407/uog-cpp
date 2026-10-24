#include "lecturer.h"
#include "ugstudent.h"
#include <iostream>

int main() {
    Lecturer khiem{"Khiem", 42, 55000};
    std::cout << khiem.get_name() << " (ID " << khiem.get_id() << "), salary "
              << khiem.get_salary() << '\n';

    UGStudent natasha{"Natasha", 20};
    std::cout << natasha.get_name() << " (ID " << natasha.get_id()
              << "), tuition " << natasha.get_tuition() << '\n';
    natasha.write_bsc_thesis();
    return 0;
}
