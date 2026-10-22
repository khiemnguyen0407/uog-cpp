#include <iostream>

int main() {
    std::cout << "How many numbers? ";
    int length{};
    std::cin >> length; // known only when the program runs

    int* numbers{new int[length]{}}; // length ints, all set to 0

    for (int i{0}; i < length; ++i) {
        numbers[i] = i * i; // the i-th int
    }
    for (int i{0}; i < length; ++i) {
        std::cout << numbers[i] << ' ';
    }
    std::cout << '\n';

    delete[] numbers; // array new needs array delete
    return 0;
}
