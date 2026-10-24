#ifndef UNIPERSON_H
#define UNIPERSON_H

#include <string>

class UniPerson {
  private:
    static int next_id; // declared here, defined in uniperson.cpp
    std::string name{};
    int id{};
    int age{};

  public:
    UniPerson(const std::string& name = "", int age = 0);
    const std::string& get_name() const;
    int get_age() const;
    int get_id() const;
};

#endif
