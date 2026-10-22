#include "value_category.h" // our little tool
#include <string>

int get_int() { return 5; }

int main() {
    int x{5};
    PRINT_VALUE_CATEGORY(5);
    PRINT_VALUE_CATEGORY(get_int());
    PRINT_VALUE_CATEGORY(x);
    PRINT_VALUE_CATEGORY(x + 1);
    PRINT_VALUE_CATEGORY(std::string{"Hello"});
    PRINT_VALUE_CATEGORY("Hello");
    PRINT_VALUE_CATEGORY(++x);
    PRINT_VALUE_CATEGORY(x++);
    return 0;
}
