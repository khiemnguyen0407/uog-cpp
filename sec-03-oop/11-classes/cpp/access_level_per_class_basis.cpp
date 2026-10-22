#include <iostream>
#include <string>

class Person {
  private:
    std::string name{};

  public:
    void set_name(const std::string& new_name) { name = new_name; }

    void greet(const Person& other) const {
        // We may use other.name: other is a Person too
        std::cout << name << " says hello to " << other.name << '\n';
    }
};

int main() {
    Person joe{};
    joe.set_name("Joe");
    Person kate{};
    kate.set_name("Kate");
    joe.greet(kate);
    return 0;
}
