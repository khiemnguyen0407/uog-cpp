#include <iostream>

template <typename T>
void print(T x) { // generic: any T
    std::cout << x << '\n';
}

void print(bool x) { // special: bool
    std::cout << std::boolalpha << x << '\n';
}

int main() {
    print<bool>(true); // template: 1
    print<>(true);     // template: 1
    print(true);       // ordinary: true
    return 0;
}
