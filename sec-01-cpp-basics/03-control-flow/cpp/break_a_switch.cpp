#include <iostream>

void print_math(int x, int y, char op) {
    switch (op) {
    case '+':
        std::cout << x << " + " << y << " = " << x + y << '\n';
        break; // done: jump to the end of the switch
    case '-':
        std::cout << x << " - " << y << " = " << x - y << '\n';
        break;
    case '/':
        std::cout << x << " / " << y << " = " << x / y << '\n';
        break;
    }
}

int main() {
    print_math(7, 2, '+');
    print_math(7, 2, '-');
    print_math(7, 2, '/');
    return 0;
}
