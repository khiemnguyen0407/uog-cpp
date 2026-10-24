#include "school.h"
#include <iostream>

int main() {
    Teacher tony{"Tony"}; // created OUTSIDE any department
    Teacher natasha{"Natasha"};
    {
        Department department{};
        department.add(tony);
        department.add(natasha);
        department.print();
    } // the department is destroyed here...

    std::cout << tony.name << " and " << natasha.name
              << " still exist\n"; // ...but its teachers are not
    return 0;
}
