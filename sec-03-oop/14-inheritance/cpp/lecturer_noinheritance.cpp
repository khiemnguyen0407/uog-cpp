#include <string>

class Lecturer { // no inheritance: everything written again
  private:
    static inline int next_id{100000}; // a SECOND, separate counter!
    std::string name{};
    int id{};
    int age{};
    double salary{};

  public:
    Lecturer(const std::string& name, int age, double salary)
        : name{name}, id{next_id++}, age{age}, salary{salary} {}

    const std::string& get_name() const { return name; } // copied...
    int get_age() const { return age; }                  // ...and
    int get_id() const { return id; }                    // pasted
    double get_salary() const { return salary; }
};

int main() {
    Lecturer khiem{"Khiem", 42, 55000};
    return 0;
}
