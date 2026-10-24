#ifndef UNIPERSON_H
#define UNIPERSON_H

#include <string>

class UniPerson {
  private:
    static inline int next_id{100000}; // ONE counter, shared by all
    std::string name{};
    int id{};
    int age{};

  public:
    UniPerson(const std::string& name = "", int age = 0)
        : name{name}, id{next_id++}, age{age} {}

    const std::string& get_name() const { return name; }
    int get_age() const { return age; }
    int get_id() const { return id; }
};

#endif
