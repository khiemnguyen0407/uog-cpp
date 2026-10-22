#include <iostream>

int main() {
    int count{1};
    while (count <= 50) {
        if (count < 10) {
            std::cout << '0'; // pad single digits: 01, 02, ...
        }
        std::cout << count << ' ';

        if (count % 10 == 0) { // every 10th number...
            std::cout << '\n'; // ...start a new line
        }
        ++count;
    }
    return 0;
}
