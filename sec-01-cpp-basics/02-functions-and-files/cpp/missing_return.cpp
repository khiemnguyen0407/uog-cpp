#include <iostream>

int get_answer() {
    std::cout << "Thinking...\n";
    // Oops: we forgot to write "return 42;"
}

int main() {
    std::cout << get_answer() << '\n';
    return 0;
}
