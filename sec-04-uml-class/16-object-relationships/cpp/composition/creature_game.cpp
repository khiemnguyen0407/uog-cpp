#include "creature.h"
#include <iostream>
#include <string>

int main() {
    std::cout << "Enter a name for your creature: ";
    std::string name{};
    std::cin >> name;
    Creature creature{name, Point2D{4, 7}};

    while (true) {
        std::cout << creature << '\n';

        std::cout << "New x and y (or -1 -1 to quit): ";
        int x{};
        int y{};
        std::cin >> x >> y;
        if (x == -1) {
            break;
        }
        creature.move_to(x, y);
    }
    return 0;
} // creature is destroyed, and its Point2D with it
