#include <iostream>

int main() {
    int sum{0};

    for (int count{0}; count < 10; ++count) { // at most 10
        std::cout << "Number to add (0 to stop): ";
        int num{};
        std::cin >> num;

        if (num == 0) {
            break; // leave the loop right now
        }
        sum += num; // same as sum = sum + num
    }

    // execution continues here after the break
    std::cout << "The sum is " << sum << '\n';
    return 0;
}
