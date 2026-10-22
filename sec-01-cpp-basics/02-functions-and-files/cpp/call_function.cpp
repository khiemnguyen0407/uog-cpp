#include <iostream>

void say_hello() { // definition of say_hello()
    std::cout << "  In say_hello(): Hello there!\n";
}

int main() {
    std::cout << "Starting main()\n";
    say_hello(); // first call
    say_hello(); // second call
    std::cout << "Ending main()\n";
    return 0;
}
