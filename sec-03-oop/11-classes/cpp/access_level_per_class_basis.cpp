#include <iostream>
#include <string>
#include <string_view>

class Person
{
private:
    std::string name{};

public:
    void kisses(const Person& p) const
    {   // we access data member "name" of object "p"
        std::cout << name << " kisses " << p.name << '\n';  
    }

    void set_name(std::string_view name)
    {   // this is the pointer to the "current" object.
        // This is why we don't need to use m_name, or name_
        // and everything still appears normal and sensible.
        this->name = name;      
    }
};

int main()
{
    Person joe;
    joe.set_name("Joe");
    Person kate;
    kate.set_name("Kate");
    joe.kisses(kate);

    return 0;
}