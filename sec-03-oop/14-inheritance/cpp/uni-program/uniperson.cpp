#include "uniperson.h"

int UniPerson::next_id{100000}; // the one definition of the counter

UniPerson::UniPerson(const std::string& name, int age)
    : name{name}, id{next_id++}, age{age} {}

const std::string& UniPerson::get_name() const { return name; }
int UniPerson::get_age() const { return age; }
int UniPerson::get_id() const { return id; }
