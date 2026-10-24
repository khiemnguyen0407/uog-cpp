#include "base_derived.h"
#include <vector>

int main() {
    std::vector<Derived> list{Derived{42.0, 24}, Derived{24.0, 42}, Derived{}};

    for (const auto& element : list) { // like "for element in list:"
        element.print();
    }
    return 0;
}
