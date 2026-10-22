#include <iostream>

int main() {
    int x{5};
    int y{6};

    int& ref{x}; // ref is another name for x

    ref = y; // does this make ref refer to y?

    std::cout << x << '\n'; // what does this print?
    return 0;
}
