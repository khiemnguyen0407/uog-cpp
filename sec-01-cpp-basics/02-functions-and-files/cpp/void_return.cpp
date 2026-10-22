#include <iostream>

void say_hi() { // void: returns no value
    std::cout << "Hi\n";
    std::cout << "I'm Khiem\n";
    return; // go back to the caller now

    std::cout << "This line never runs\n";
}

int main() {
    say_hi();
    std::cout << "Back in main()\n";
    return 0;
}
