#include <iostream>

int main() {
    constexpr int min_ride_height_cm{140}; // named, not magic

    std::cout << "Enter your height (in cm): ";
    int height{};
    std::cin >> height;

    if (height >= min_ride_height_cm) {
        std::cout << "You are tall enough to ride.\n";
    } else {
        std::cout << "Sorry, too short to ride.\n";
    }
    return 0;
}
