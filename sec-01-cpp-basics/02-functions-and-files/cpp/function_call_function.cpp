#include <iostream>

void do_b() { std::cout << "    In do_b()\n"; }

void do_a() {
    std::cout << "  Starting do_a()\n";
    do_b();
    std::cout << "  Ending do_a()\n";
}

int main() {
    std::cout << "Starting main()\n";
    do_a();
    std::cout << "Ending main()\n";
    return 0;
}
