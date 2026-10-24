#ifndef SCHOOL_H
#define SCHOOL_H

#include <functional> // std::reference_wrapper
#include <iostream>
#include <string>
#include <vector>
struct Teacher { // passive data, so a struct (Chapter 10)
    std::string name{};
};

class Department {
  private:
    std::vector<std::reference_wrapper<const Teacher>> teachers{};

  public:
    void add(const Teacher& teacher) { teachers.push_back(teacher); }

    void print() const {
        std::cout << "Department staff:";
        for (const Teacher& teacher : teachers) {
            std::cout << ' ' << teacher.name;
        }
        std::cout << '\n';
    }
};
#endif
