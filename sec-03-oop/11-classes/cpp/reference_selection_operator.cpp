#include <iostream>

struct Employee
{
    int id{};
    int age{};
    double wage{};
};

void print_employee(const Employee& employee)
{
    // Use member selection operator (.) to select member from reference to struct
    std::cout << "Id: " << employee.id << '\n';
    std::cout << "Age: " << employee.age << '\n';
    std::cout << "Wage: " << employee.wage << '\n';
}

int main()
{
    Employee joe{ 1, 34, 65000.0 };
    joe.wage = 68000.0;
    print_employee(joe);

    return 0;
}